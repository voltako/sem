# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/nikita/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nikita/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_.dir/flags.make

CMakeFiles/_.dir/main.c.o: CMakeFiles/_.dir/flags.make
CMakeFiles/_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/_.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/_.dir/main.c.o   -c "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/main.c"

CMakeFiles/_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/main.c" > CMakeFiles/_.dir/main.c.i

CMakeFiles/_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/main.c" -o CMakeFiles/_.dir/main.c.s

# Object files for target _
__OBJECTS = \
"CMakeFiles/_.dir/main.c.o"

# External object files for target _
__EXTERNAL_OBJECTS =

_ : CMakeFiles/_.dir/main.c.o
_ : CMakeFiles/_.dir/build.make
_ : CMakeFiles/_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable _"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_.dir/build: _

.PHONY : CMakeFiles/_.dir/build

CMakeFiles/_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_.dir/clean

CMakeFiles/_.dir/depend:
	cd "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки" "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки" "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug" "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug" "/home/nikita/Рабочий стол/сортировки сортировочки/простые вставки/cmake-build-debug/CMakeFiles/_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_.dir/depend

