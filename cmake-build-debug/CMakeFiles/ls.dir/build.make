# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\SHELL\Mariam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\SHELL\Mariam\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ls.dir/flags.make

CMakeFiles/ls.dir/ls.c.obj: CMakeFiles/ls.dir/flags.make
CMakeFiles/ls.dir/ls.c.obj: ../ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\SHELL\Mariam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ls.dir/ls.c.obj"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ls.dir\ls.c.obj   -c F:\SHELL\Mariam\ls.c

CMakeFiles/ls.dir/ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ls.dir/ls.c.i"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SHELL\Mariam\ls.c > CMakeFiles\ls.dir\ls.c.i

CMakeFiles/ls.dir/ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ls.dir/ls.c.s"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SHELL\Mariam\ls.c -o CMakeFiles\ls.dir\ls.c.s

# Object files for target ls
ls_OBJECTS = \
"CMakeFiles/ls.dir/ls.c.obj"

# External object files for target ls
ls_EXTERNAL_OBJECTS =

ls.exe: CMakeFiles/ls.dir/ls.c.obj
ls.exe: CMakeFiles/ls.dir/build.make
ls.exe: CMakeFiles/ls.dir/linklibs.rsp
ls.exe: CMakeFiles/ls.dir/objects1.rsp
ls.exe: CMakeFiles/ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\SHELL\Mariam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ls.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ls.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ls.dir/build: ls.exe

.PHONY : CMakeFiles/ls.dir/build

CMakeFiles/ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ls.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ls.dir/clean

CMakeFiles/ls.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\SHELL\Mariam F:\SHELL\Mariam F:\SHELL\Mariam\cmake-build-debug F:\SHELL\Mariam\cmake-build-debug F:\SHELL\Mariam\cmake-build-debug\CMakeFiles\ls.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ls.dir/depend

