# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Samson\CLionProjects\Fib1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Samson\CLionProjects\Fib1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fib1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fib1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fib1.dir/flags.make

CMakeFiles/Fib1.dir/main.c.obj: CMakeFiles/Fib1.dir/flags.make
CMakeFiles/Fib1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Samson\CLionProjects\Fib1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fib1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Fib1.dir\main.c.obj   -c C:\Users\Samson\CLionProjects\Fib1\main.c

CMakeFiles/Fib1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fib1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Samson\CLionProjects\Fib1\main.c > CMakeFiles\Fib1.dir\main.c.i

CMakeFiles/Fib1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fib1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Samson\CLionProjects\Fib1\main.c -o CMakeFiles\Fib1.dir\main.c.s

# Object files for target Fib1
Fib1_OBJECTS = \
"CMakeFiles/Fib1.dir/main.c.obj"

# External object files for target Fib1
Fib1_EXTERNAL_OBJECTS =

Fib1.exe: CMakeFiles/Fib1.dir/main.c.obj
Fib1.exe: CMakeFiles/Fib1.dir/build.make
Fib1.exe: CMakeFiles/Fib1.dir/linklibs.rsp
Fib1.exe: CMakeFiles/Fib1.dir/objects1.rsp
Fib1.exe: CMakeFiles/Fib1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Samson\CLionProjects\Fib1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Fib1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Fib1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fib1.dir/build: Fib1.exe

.PHONY : CMakeFiles/Fib1.dir/build

CMakeFiles/Fib1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Fib1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Fib1.dir/clean

CMakeFiles/Fib1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Samson\CLionProjects\Fib1 C:\Users\Samson\CLionProjects\Fib1 C:\Users\Samson\CLionProjects\Fib1\cmake-build-debug C:\Users\Samson\CLionProjects\Fib1\cmake-build-debug C:\Users\Samson\CLionProjects\Fib1\cmake-build-debug\CMakeFiles\Fib1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fib1.dir/depend

