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
include CMakeFiles/spec2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spec2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spec2.dir/flags.make

CMakeFiles/spec2.dir/spec2.c.obj: CMakeFiles/spec2.dir/flags.make
CMakeFiles/spec2.dir/spec2.c.obj: ../spec2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\SHELL\Mariam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spec2.dir/spec2.c.obj"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\spec2.dir\spec2.c.obj   -c F:\SHELL\Mariam\spec2.c

CMakeFiles/spec2.dir/spec2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spec2.dir/spec2.c.i"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SHELL\Mariam\spec2.c > CMakeFiles\spec2.dir\spec2.c.i

CMakeFiles/spec2.dir/spec2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spec2.dir/spec2.c.s"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SHELL\Mariam\spec2.c -o CMakeFiles\spec2.dir\spec2.c.s

# Object files for target spec2
spec2_OBJECTS = \
"CMakeFiles/spec2.dir/spec2.c.obj"

# External object files for target spec2
spec2_EXTERNAL_OBJECTS =

spec2.exe: CMakeFiles/spec2.dir/spec2.c.obj
spec2.exe: CMakeFiles/spec2.dir/build.make
spec2.exe: CMakeFiles/spec2.dir/linklibs.rsp
spec2.exe: CMakeFiles/spec2.dir/objects1.rsp
spec2.exe: CMakeFiles/spec2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\SHELL\Mariam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable spec2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\spec2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spec2.dir/build: spec2.exe

.PHONY : CMakeFiles/spec2.dir/build

CMakeFiles/spec2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\spec2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/spec2.dir/clean

CMakeFiles/spec2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\SHELL\Mariam F:\SHELL\Mariam F:\SHELL\Mariam\cmake-build-debug F:\SHELL\Mariam\cmake-build-debug F:\SHELL\Mariam\cmake-build-debug\CMakeFiles\spec2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spec2.dir/depend

