# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/animesh/Software/clion-2018.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/animesh/Software/clion-2018.3.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/animesh/Code/Contest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/animesh/Code/Contest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Current.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Current.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Current.dir/flags.make

CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.o: CMakeFiles/Current.dir/flags.make
CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.o: ../Codechef/LAZZYSEG.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/animesh/Code/Contest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.o -c /home/animesh/Code/Contest/Codechef/LAZZYSEG.cpp

CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/animesh/Code/Contest/Codechef/LAZZYSEG.cpp > CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.i

CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/animesh/Code/Contest/Codechef/LAZZYSEG.cpp -o CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.s

# Object files for target Current
Current_OBJECTS = \
"CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.o"

# External object files for target Current
Current_EXTERNAL_OBJECTS =

Current: CMakeFiles/Current.dir/Codechef/LAZZYSEG.cpp.o
Current: CMakeFiles/Current.dir/build.make
Current: CMakeFiles/Current.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/animesh/Code/Contest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Current"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Current.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Current.dir/build: Current

.PHONY : CMakeFiles/Current.dir/build

CMakeFiles/Current.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Current.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Current.dir/clean

CMakeFiles/Current.dir/depend:
	cd /home/animesh/Code/Contest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/animesh/Code/Contest /home/animesh/Code/Contest /home/animesh/Code/Contest/cmake-build-debug /home/animesh/Code/Contest/cmake-build-debug /home/animesh/Code/Contest/cmake-build-debug/CMakeFiles/Current.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Current.dir/depend
