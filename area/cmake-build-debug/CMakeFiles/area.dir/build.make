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
CMAKE_SOURCE_DIR = C:\Users\Samson\CLionProjects\area

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Samson\CLionProjects\area\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/area.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/area.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/area.dir/flags.make

CMakeFiles/area.dir/main.c.obj: CMakeFiles/area.dir/flags.make
CMakeFiles/area.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Samson\CLionProjects\area\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/area.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\area.dir\main.c.obj   -c C:\Users\Samson\CLionProjects\area\main.c

CMakeFiles/area.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/area.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Samson\CLionProjects\area\main.c > CMakeFiles\area.dir\main.c.i

CMakeFiles/area.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/area.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Samson\CLionProjects\area\main.c -o CMakeFiles\area.dir\main.c.s

# Object files for target area
area_OBJECTS = \
"CMakeFiles/area.dir/main.c.obj"

# External object files for target area
area_EXTERNAL_OBJECTS =

area.exe: CMakeFiles/area.dir/main.c.obj
area.exe: CMakeFiles/area.dir/build.make
area.exe: CMakeFiles/area.dir/linklibs.rsp
area.exe: CMakeFiles/area.dir/objects1.rsp
area.exe: CMakeFiles/area.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Samson\CLionProjects\area\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable area.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\area.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/area.dir/build: area.exe

.PHONY : CMakeFiles/area.dir/build

CMakeFiles/area.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\area.dir\cmake_clean.cmake
.PHONY : CMakeFiles/area.dir/clean

CMakeFiles/area.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Samson\CLionProjects\area C:\Users\Samson\CLionProjects\area C:\Users\Samson\CLionProjects\area\cmake-build-debug C:\Users\Samson\CLionProjects\area\cmake-build-debug C:\Users\Samson\CLionProjects\area\cmake-build-debug\CMakeFiles\area.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/area.dir/depend

