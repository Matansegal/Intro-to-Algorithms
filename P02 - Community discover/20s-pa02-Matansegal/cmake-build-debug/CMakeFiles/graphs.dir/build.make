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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/graphs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphs.dir/flags.make

CMakeFiles/graphs.dir/main.cpp.obj: CMakeFiles/graphs.dir/flags.make
CMakeFiles/graphs.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphs.dir/main.cpp.obj"
	C:\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\graphs.dir\main.cpp.obj -c "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\main.cpp"

CMakeFiles/graphs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphs.dir/main.cpp.i"
	C:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\main.cpp" > CMakeFiles\graphs.dir\main.cpp.i

CMakeFiles/graphs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphs.dir/main.cpp.s"
	C:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\main.cpp" -o CMakeFiles\graphs.dir\main.cpp.s

CMakeFiles/graphs.dir/utilities.cpp.obj: CMakeFiles/graphs.dir/flags.make
CMakeFiles/graphs.dir/utilities.cpp.obj: ../utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphs.dir/utilities.cpp.obj"
	C:\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\graphs.dir\utilities.cpp.obj -c "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\utilities.cpp"

CMakeFiles/graphs.dir/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphs.dir/utilities.cpp.i"
	C:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\utilities.cpp" > CMakeFiles\graphs.dir\utilities.cpp.i

CMakeFiles/graphs.dir/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphs.dir/utilities.cpp.s"
	C:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\utilities.cpp" -o CMakeFiles\graphs.dir\utilities.cpp.s

# Object files for target graphs
graphs_OBJECTS = \
"CMakeFiles/graphs.dir/main.cpp.obj" \
"CMakeFiles/graphs.dir/utilities.cpp.obj"

# External object files for target graphs
graphs_EXTERNAL_OBJECTS =

graphs.exe: CMakeFiles/graphs.dir/main.cpp.obj
graphs.exe: CMakeFiles/graphs.dir/utilities.cpp.obj
graphs.exe: CMakeFiles/graphs.dir/build.make
graphs.exe: CMakeFiles/graphs.dir/linklibs.rsp
graphs.exe: CMakeFiles/graphs.dir/objects1.rsp
graphs.exe: CMakeFiles/graphs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graphs.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\graphs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphs.dir/build: graphs.exe

.PHONY : CMakeFiles/graphs.dir/build

CMakeFiles/graphs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graphs.dir\cmake_clean.cmake
.PHONY : CMakeFiles/graphs.dir/clean

CMakeFiles/graphs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal" "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal" "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug" "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug" "C:\Users\matan\Documents\school\7 Spring 2020\CS3353\P02\20s-pa02-doover-Matansegal\cmake-build-debug\CMakeFiles\graphs.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/graphs.dir/depend
