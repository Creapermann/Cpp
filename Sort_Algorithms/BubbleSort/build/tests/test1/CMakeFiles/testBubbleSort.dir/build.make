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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build

# Include any dependencies generated for this target.
include tests/test1/CMakeFiles/testBubbleSort.dir/depend.make

# Include the progress variables for this target.
include tests/test1/CMakeFiles/testBubbleSort.dir/progress.make

# Include the compile flags for this target's objects.
include tests/test1/CMakeFiles/testBubbleSort.dir/flags.make

tests/test1/CMakeFiles/testBubbleSort.dir/maintest.cpp.o: tests/test1/CMakeFiles/testBubbleSort.dir/flags.make
tests/test1/CMakeFiles/testBubbleSort.dir/maintest.cpp.o: ../tests/test1/maintest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/test1/CMakeFiles/testBubbleSort.dir/maintest.cpp.o"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testBubbleSort.dir/maintest.cpp.o -c /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1/maintest.cpp

tests/test1/CMakeFiles/testBubbleSort.dir/maintest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testBubbleSort.dir/maintest.cpp.i"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1/maintest.cpp > CMakeFiles/testBubbleSort.dir/maintest.cpp.i

tests/test1/CMakeFiles/testBubbleSort.dir/maintest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testBubbleSort.dir/maintest.cpp.s"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1/maintest.cpp -o CMakeFiles/testBubbleSort.dir/maintest.cpp.s

tests/test1/CMakeFiles/testBubbleSort.dir/testFile.cpp.o: tests/test1/CMakeFiles/testBubbleSort.dir/flags.make
tests/test1/CMakeFiles/testBubbleSort.dir/testFile.cpp.o: ../tests/test1/testFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/test1/CMakeFiles/testBubbleSort.dir/testFile.cpp.o"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testBubbleSort.dir/testFile.cpp.o -c /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1/testFile.cpp

tests/test1/CMakeFiles/testBubbleSort.dir/testFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testBubbleSort.dir/testFile.cpp.i"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1/testFile.cpp > CMakeFiles/testBubbleSort.dir/testFile.cpp.i

tests/test1/CMakeFiles/testBubbleSort.dir/testFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testBubbleSort.dir/testFile.cpp.s"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1/testFile.cpp -o CMakeFiles/testBubbleSort.dir/testFile.cpp.s

# Object files for target testBubbleSort
testBubbleSort_OBJECTS = \
"CMakeFiles/testBubbleSort.dir/maintest.cpp.o" \
"CMakeFiles/testBubbleSort.dir/testFile.cpp.o"

# External object files for target testBubbleSort
testBubbleSort_EXTERNAL_OBJECTS =

tests/test1/testBubbleSort: tests/test1/CMakeFiles/testBubbleSort.dir/maintest.cpp.o
tests/test1/testBubbleSort: tests/test1/CMakeFiles/testBubbleSort.dir/testFile.cpp.o
tests/test1/testBubbleSort: tests/test1/CMakeFiles/testBubbleSort.dir/build.make
tests/test1/testBubbleSort: tests/test1/CMakeFiles/testBubbleSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testBubbleSort"
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testBubbleSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/test1/CMakeFiles/testBubbleSort.dir/build: tests/test1/testBubbleSort

.PHONY : tests/test1/CMakeFiles/testBubbleSort.dir/build

tests/test1/CMakeFiles/testBubbleSort.dir/clean:
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 && $(CMAKE_COMMAND) -P CMakeFiles/testBubbleSort.dir/cmake_clean.cmake
.PHONY : tests/test1/CMakeFiles/testBubbleSort.dir/clean

tests/test1/CMakeFiles/testBubbleSort.dir/depend:
	cd /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/tests/test1 /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1 /home/creapermann/Data/Programming/Cpp/CodeFiles/29.11.2020_SortAlgorithm_Coll/31.10.2020_bubbleSort/build/tests/test1/CMakeFiles/testBubbleSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/test1/CMakeFiles/testBubbleSort.dir/depend
