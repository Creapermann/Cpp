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
CMAKE_SOURCE_DIR = /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/lib.dir/flags.make

lib/CMakeFiles/lib.dir/src/main.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/main.cpp.o: ../lib/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/lib.dir/src/main.cpp.o"
	cd /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/main.cpp.o -c /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/lib/src/main.cpp

lib/CMakeFiles/lib.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/main.cpp.i"
	cd /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/lib/src/main.cpp > CMakeFiles/lib.dir/src/main.cpp.i

lib/CMakeFiles/lib.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/main.cpp.s"
	cd /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/lib/src/main.cpp -o CMakeFiles/lib.dir/src/main.cpp.s

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/src/main.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

lib/liblib.so: lib/CMakeFiles/lib.dir/src/main.cpp.o
lib/liblib.so: lib/CMakeFiles/lib.dir/build.make
lib/liblib.so: lib/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liblib.so"
	cd /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/lib.dir/build: lib/liblib.so

.PHONY : lib/CMakeFiles/lib.dir/build

lib/CMakeFiles/lib.dir/clean:
	cd /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/lib.dir/clean

lib/CMakeFiles/lib.dir/depend:
	cd /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/lib /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib /mnt/c/Users/Creap/Data/Programming/C++/Codefiles/28.12.2020_SnakeTheGame/build/lib/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/lib.dir/depend

