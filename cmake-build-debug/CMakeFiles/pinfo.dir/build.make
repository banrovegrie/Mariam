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
include CMakeFiles/pinfo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pinfo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pinfo.dir/flags.make

CMakeFiles/pinfo.dir/pinfo.c.obj: CMakeFiles/pinfo.dir/flags.make
CMakeFiles/pinfo.dir/pinfo.c.obj: ../pinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\SHELL\Mariam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pinfo.dir/pinfo.c.obj"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pinfo.dir\pinfo.c.obj   -c F:\SHELL\Mariam\pinfo.c

CMakeFiles/pinfo.dir/pinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pinfo.dir/pinfo.c.i"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\SHELL\Mariam\pinfo.c > CMakeFiles\pinfo.dir\pinfo.c.i

CMakeFiles/pinfo.dir/pinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pinfo.dir/pinfo.c.s"
	C:\Users\GAUTAM~1\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\SHELL\Mariam\pinfo.c -o CMakeFiles\pinfo.dir\pinfo.c.s

# Object files for target pinfo
pinfo_OBJECTS = \
"CMakeFiles/pinfo.dir/pinfo.c.obj"

# External object files for target pinfo
pinfo_EXTERNAL_OBJECTS =

pinfo.exe: CMakeFiles/pinfo.dir/pinfo.c.obj
pinfo.exe: CMakeFiles/pinfo.dir/build.make
pinfo.exe: CMakeFiles/pinfo.dir/linklibs.rsp
pinfo.exe: CMakeFiles/pinfo.dir/objects1.rsp
pinfo.exe: CMakeFiles/pinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\SHELL\Mariam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pinfo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pinfo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pinfo.dir/build: pinfo.exe

.PHONY : CMakeFiles/pinfo.dir/build

CMakeFiles/pinfo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pinfo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pinfo.dir/clean

CMakeFiles/pinfo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\SHELL\Mariam F:\SHELL\Mariam F:\SHELL\Mariam\cmake-build-debug F:\SHELL\Mariam\cmake-build-debug F:\SHELL\Mariam\cmake-build-debug\CMakeFiles\pinfo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pinfo.dir/depend

