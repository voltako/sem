#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#define BUCKETS     1024
#define swap_endian(x, size) \
{ \
    /*switch(sizeof(x)) { \*/ \
    switch(size) { \
        case 8: \
            x = (((unsigned long long)(x) << 56) | \
            (((unsigned long long)x << 40) & 0xff000000000000ULL) | \
            (((unsigned long long)x << 24) & 0xff0000000000ULL) | \
            (((unsigned long long)x <<  8) & 0xff00000000ULL) | \
            (((unsigned long long)x >>  8) & 0xff000000ULL) | \
            (((unsigned long long)x >> 24) & 0xff0000ULL) | \
            (((unsigned long long)x >> 40) & 0xff00ULL) | \
             ((unsigned long long)x >> 56)); \
            break; \
        case 4: \
            x = (x >> 24) | ((x << 8) & 0x00ff0000) | ((x >> 8) & 0x0000ff00) | (x << 24); \
            break; \
        case 2: \
            x = (x >> 8) | (x << 8); \
            break; \
    } \
}
struct quantum {
    unsigned long long val;
    unsigned int frequency;
    struct quantum *next;
    struct quantum *prev;
};

struct quantum *hash[BUCKETS];
unsigned long long entries;
unsigned long long unique;


static int compar(const void *_a, const void *_b)
{
    struct quantum * const *a = (struct quantum * const *) _a;
    struct quantum * const *b = (struct quantum * const *) _b;

    if (!*a || !*b)
        return 1;

    if ((*a)->frequency > (*b)->frequency)
        return -1;
    else if ((*a)->frequency == (*b)->frequency)
        return 0;
    else
        return 1;
}

static int val_to_ascii(unsigned long long val, unsigned int size)
{
    unsigned char c = 0;
    int i;
    double shen;

    swap_endian(val, size);

    for (i = size; i; i--) {
        c = (val >> (8 * (i -1))) & 0xff;
        printf("%c", isprint(c) ? c : '.');
    }
    printf("| ");


    return 0;
}

static int val_to_hex(unsigned long long int val, unsigned int size)
{
    unsigned char c;
    int i;

    printf("0x");
    for (i = size; i; i--) {
        c = (val >> (8 * (i -1))) & 0xff;
        printf("%02x", c);

    }


    return 0;
}

static int print_sorted_array(struct quantum **hash, unsigned int quantum_size)
{
    struct quantum *arr[unique];
    struct quantum *quantum;
    int i, j;

    j = 0;
    for (i = 0; i < BUCKETS; i++) {
        quantum = hash[i];
        while (quantum) {
            arr[j++] = quantum;
            quantum = quantum->next;
            if (quantum == hash[i])
                break;
        }
    }

    qsort(arr, unique, sizeof(arr[0]), compar);
    printf("\n");
    for (i = 0; i < unique; i++) {
        printf("%04d: ", i);

        val_to_hex(arr[i]->val, quantum_size);
        val_to_ascii(arr[i]->val, quantum_size);

        printf("%0.02f%% %d\n", (float)arr[i]->frequency / (float)entries * (float)100, (unsigned int)arr[i]->frequency);

        free(arr[i]);
    }

    return 0;
}

int main(int argc, char **argv)
{
    unsigned int offset;
    unsigned int quantum_size;
    unsigned int count;
    struct stat st;
    char *target;
    int nr;
    int i;
    int fd;

    target = "/home/nikita/Рабочий стол/entrop/qwe.txt";
    if (argc > 1)
        target = argv[1];

    quantum_size = 1; // byte quantum_size
    if (argc > 2)
        quantum_size = strtoul(argv[2], NULL, 0);
    assert(quantum_size <= sizeof(unsigned long long));

    offset = 0;
    if (argc > 3)
        offset = strtoul(argv[3], NULL, 0);

    fd = open(target, O_RDONLY);
    if (-1 == fd) {
        perror(target);
        return 1;
    }

    fstat(fd, &st);
    count = st.st_size;
    if (argc > 4)
        count = strtoul(argv[4], NULL, 0);
    count = count > st.st_size ? st.st_size : count;

    printf("target file:    %s\n", target);
    printf("start offset:   %d\n", offset);
    printf("analyzed bytes: %d\n", count);
    printf("quantum size:   %d\n", quantum_size);

    lseek(fd, offset, SEEK_SET);
    do {
        struct quantum *quantum;
        unsigned long long val;
        next:

        val = 0;
        nr = read(fd, &val, quantum_size);
        if (!nr || nr != quantum_size)
            break;

        quantum = hash[val % BUCKETS];
        while (quantum) {
            if (quantum->val == val) { // increment frequency:
                quantum->frequency++;
                entries++;
                goto next;
            }

            // new quantum:
            quantum = quantum->next;
            if (quantum == hash[val % BUCKETS]) // end of list:
                break;
        }

        assert(quantum = malloc(sizeof(*quantum)));
        quantum->val = val;
        quantum->frequency = 1;
        quantum->next = quantum;
        quantum->prev = quantum;
        entries++;
        unique++;

        if (!hash[val % BUCKETS]) // new quantum:
            hash[val % BUCKETS] = quantum;
        else {
            struct quantum *head;

            head = hash[val % BUCKETS];
            quantum->next = head;
            quantum->prev = head->prev;
            head->prev->next = quantum;
            head->prev = quantum;
        }
    } while (nr < count);

    printf("unique quanta:  %lld\n", unique);
    printf("quanta:         %lld\n", entries);

    if (unique < (1024 * 1024))
        print_sorted_array(hash, quantum_size);
    else {
        printf("\nunsorted hash:\n");
        for (i = 0; i < BUCKETS; i++) {
            struct quantum *quantum;

            quantum = hash[i];
            while (quantum) {
                struct quantum *next;

                printf("hash[%04d]: 0x%016llx [%02.2f%%] %d\n", i, quantum->val, (float)quantum->frequency / (float)entries * (float)100, quantum->frequency);// * 100);
                next = quantum->next;
                free(quantum);
                quantum = next;
                if (quantum == hash[i])
                    break;
            }
        }
    }

    close(fd);

    return 0;
}
