# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Binary_Search.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Binary_Search.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Binary_Search.dir/flags.make

CMakeFiles/Binary_Search.dir/main.cpp.o: CMakeFiles/Binary_Search.dir/flags.make
CMakeFiles/Binary_Search.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Binary_Search.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Binary_Search.dir/main.cpp.o -c /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/main.cpp

CMakeFiles/Binary_Search.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Binary_Search.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/main.cpp > CMakeFiles/Binary_Search.dir/main.cpp.i

CMakeFiles/Binary_Search.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Binary_Search.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/main.cpp -o CMakeFiles/Binary_Search.dir/main.cpp.s

# Object files for target Binary_Search
Binary_Search_OBJECTS = \
"CMakeFiles/Binary_Search.dir/main.cpp.o"

# External object files for target Binary_Search
Binary_Search_EXTERNAL_OBJECTS =

Binary_Search: CMakeFiles/Binary_Search.dir/main.cpp.o
Binary_Search: CMakeFiles/Binary_Search.dir/build.make
Binary_Search: CMakeFiles/Binary_Search.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Binary_Search"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Binary_Search.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Binary_Search.dir/build: Binary_Search

.PHONY : CMakeFiles/Binary_Search.dir/build

CMakeFiles/Binary_Search.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Binary_Search.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Binary_Search.dir/clean

CMakeFiles/Binary_Search.dir/depend:
	cd /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug /Users/thanaphonchavengsaksongkram/Projects/Algorithms/Algorithms/Binary-Search/cmake-build-debug/CMakeFiles/Binary_Search.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Binary_Search.dir/depend

