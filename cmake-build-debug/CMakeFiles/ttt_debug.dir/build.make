# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/inte/Documents/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/inte/Documents/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/inte/CLionProjects/PSEgit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/inte/CLionProjects/PSEgit/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ttt_debug.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ttt_debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ttt_debug.dir/flags.make

CMakeFiles/ttt_debug.dir/main.cpp.o: CMakeFiles/ttt_debug.dir/flags.make
CMakeFiles/ttt_debug.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/inte/CLionProjects/PSEgit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ttt_debug.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ttt_debug.dir/main.cpp.o -c /home/inte/CLionProjects/PSEgit/main.cpp

CMakeFiles/ttt_debug.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ttt_debug.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/inte/CLionProjects/PSEgit/main.cpp > CMakeFiles/ttt_debug.dir/main.cpp.i

CMakeFiles/ttt_debug.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ttt_debug.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/inte/CLionProjects/PSEgit/main.cpp -o CMakeFiles/ttt_debug.dir/main.cpp.s

# Object files for target ttt_debug
ttt_debug_OBJECTS = \
"CMakeFiles/ttt_debug.dir/main.cpp.o"

# External object files for target ttt_debug
ttt_debug_EXTERNAL_OBJECTS =

ttt_debug: CMakeFiles/ttt_debug.dir/main.cpp.o
ttt_debug: CMakeFiles/ttt_debug.dir/build.make
ttt_debug: CMakeFiles/ttt_debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/inte/CLionProjects/PSEgit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ttt_debug"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ttt_debug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ttt_debug.dir/build: ttt_debug

.PHONY : CMakeFiles/ttt_debug.dir/build

CMakeFiles/ttt_debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ttt_debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ttt_debug.dir/clean

CMakeFiles/ttt_debug.dir/depend:
	cd /home/inte/CLionProjects/PSEgit/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/inte/CLionProjects/PSEgit /home/inte/CLionProjects/PSEgit /home/inte/CLionProjects/PSEgit/cmake-build-debug /home/inte/CLionProjects/PSEgit/cmake-build-debug /home/inte/CLionProjects/PSEgit/cmake-build-debug/CMakeFiles/ttt_debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ttt_debug.dir/depend

