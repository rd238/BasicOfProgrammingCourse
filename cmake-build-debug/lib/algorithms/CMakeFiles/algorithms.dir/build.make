# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "D:\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CLion 2023.3.4\Projects"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CLion 2023.3.4\Projects\cmake-build-debug"

# Include any dependencies generated for this target.
include lib/algorithms/CMakeFiles/algorithms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/algorithms/CMakeFiles/algorithms.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/algorithms/CMakeFiles/algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include lib/algorithms/CMakeFiles/algorithms.dir/flags.make

lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj: lib/algorithms/CMakeFiles/algorithms.dir/flags.make
lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj: D:/CLion\ 2023.3.4/Projects/lib/algorithms/algorithm.c
lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj: lib/algorithms/CMakeFiles/algorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\CLion 2023.3.4\Projects\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj"
	cd /d "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" && "D:\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj -MF CMakeFiles\algorithms.dir\algorithm.c.obj.d -o CMakeFiles\algorithms.dir\algorithm.c.obj -c "D:\CLion 2023.3.4\Projects\lib\algorithms\algorithm.c"

lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/algorithms.dir/algorithm.c.i"
	cd /d "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" && "D:\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\CLion 2023.3.4\Projects\lib\algorithms\algorithm.c" > CMakeFiles\algorithms.dir\algorithm.c.i

lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/algorithms.dir/algorithm.c.s"
	cd /d "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" && "D:\CLion 2023.3.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\CLion 2023.3.4\Projects\lib\algorithms\algorithm.c" -o CMakeFiles\algorithms.dir\algorithm.c.s

# Object files for target algorithms
algorithms_OBJECTS = \
"CMakeFiles/algorithms.dir/algorithm.c.obj"

# External object files for target algorithms
algorithms_EXTERNAL_OBJECTS =

lib/algorithms/libalgorithms.a: lib/algorithms/CMakeFiles/algorithms.dir/algorithm.c.obj
lib/algorithms/libalgorithms.a: lib/algorithms/CMakeFiles/algorithms.dir/build.make
lib/algorithms/libalgorithms.a: lib/algorithms/CMakeFiles/algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\CLion 2023.3.4\Projects\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libalgorithms.a"
	cd /d "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" && $(CMAKE_COMMAND) -P CMakeFiles\algorithms.dir\cmake_clean_target.cmake
	cd /d "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/algorithms/CMakeFiles/algorithms.dir/build: lib/algorithms/libalgorithms.a
.PHONY : lib/algorithms/CMakeFiles/algorithms.dir/build

lib/algorithms/CMakeFiles/algorithms.dir/clean:
	cd /d "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" && $(CMAKE_COMMAND) -P CMakeFiles\algorithms.dir\cmake_clean.cmake
.PHONY : lib/algorithms/CMakeFiles/algorithms.dir/clean

lib/algorithms/CMakeFiles/algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\CLion 2023.3.4\Projects" "D:\CLion 2023.3.4\Projects\lib\algorithms" "D:\CLion 2023.3.4\Projects\cmake-build-debug" "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms" "D:\CLion 2023.3.4\Projects\cmake-build-debug\lib\algorithms\CMakeFiles\algorithms.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : lib/algorithms/CMakeFiles/algorithms.dir/depend

