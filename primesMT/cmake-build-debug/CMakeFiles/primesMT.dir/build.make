# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Study\C333\ClassLab\Labs\Lab3\primesMT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Study\C333\ClassLab\Labs\Lab3\primesMT\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/primesMT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/primesMT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/primesMT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/primesMT.dir/flags.make

CMakeFiles/primesMT.dir/primesMT.c.obj: CMakeFiles/primesMT.dir/flags.make
CMakeFiles/primesMT.dir/primesMT.c.obj: ../primesMT.c
CMakeFiles/primesMT.dir/primesMT.c.obj: CMakeFiles/primesMT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\C333\ClassLab\Labs\Lab3\primesMT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/primesMT.dir/primesMT.c.obj"
	D:\Software\MINGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/primesMT.dir/primesMT.c.obj -MF CMakeFiles\primesMT.dir\primesMT.c.obj.d -o CMakeFiles\primesMT.dir\primesMT.c.obj -c D:\Study\C333\ClassLab\Labs\Lab3\primesMT\primesMT.c

CMakeFiles/primesMT.dir/primesMT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/primesMT.dir/primesMT.c.i"
	D:\Software\MINGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Study\C333\ClassLab\Labs\Lab3\primesMT\primesMT.c > CMakeFiles\primesMT.dir\primesMT.c.i

CMakeFiles/primesMT.dir/primesMT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/primesMT.dir/primesMT.c.s"
	D:\Software\MINGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Study\C333\ClassLab\Labs\Lab3\primesMT\primesMT.c -o CMakeFiles\primesMT.dir\primesMT.c.s

# Object files for target primesMT
primesMT_OBJECTS = \
"CMakeFiles/primesMT.dir/primesMT.c.obj"

# External object files for target primesMT
primesMT_EXTERNAL_OBJECTS =

primesMT.exe: CMakeFiles/primesMT.dir/primesMT.c.obj
primesMT.exe: CMakeFiles/primesMT.dir/build.make
primesMT.exe: CMakeFiles/primesMT.dir/linklibs.rsp
primesMT.exe: CMakeFiles/primesMT.dir/objects1.rsp
primesMT.exe: CMakeFiles/primesMT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Study\C333\ClassLab\Labs\Lab3\primesMT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable primesMT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\primesMT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/primesMT.dir/build: primesMT.exe
.PHONY : CMakeFiles/primesMT.dir/build

CMakeFiles/primesMT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\primesMT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/primesMT.dir/clean

CMakeFiles/primesMT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Study\C333\ClassLab\Labs\Lab3\primesMT D:\Study\C333\ClassLab\Labs\Lab3\primesMT D:\Study\C333\ClassLab\Labs\Lab3\primesMT\cmake-build-debug D:\Study\C333\ClassLab\Labs\Lab3\primesMT\cmake-build-debug D:\Study\C333\ClassLab\Labs\Lab3\primesMT\cmake-build-debug\CMakeFiles\primesMT.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/primesMT.dir/depend

