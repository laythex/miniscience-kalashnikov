# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laythe/miniscience-kalashnikov/01-meshes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laythe/miniscience-kalashnikov/01-meshes/build

# Include any dependencies generated for this target.
include CMakeFiles/perry.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/perry.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/perry.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perry.dir/flags.make

CMakeFiles/perry.dir/perry.cpp.o: CMakeFiles/perry.dir/flags.make
CMakeFiles/perry.dir/perry.cpp.o: ../perry.cpp
CMakeFiles/perry.dir/perry.cpp.o: CMakeFiles/perry.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laythe/miniscience-kalashnikov/01-meshes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/perry.dir/perry.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/perry.dir/perry.cpp.o -MF CMakeFiles/perry.dir/perry.cpp.o.d -o CMakeFiles/perry.dir/perry.cpp.o -c /home/laythe/miniscience-kalashnikov/01-meshes/perry.cpp

CMakeFiles/perry.dir/perry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/perry.dir/perry.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laythe/miniscience-kalashnikov/01-meshes/perry.cpp > CMakeFiles/perry.dir/perry.cpp.i

CMakeFiles/perry.dir/perry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/perry.dir/perry.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laythe/miniscience-kalashnikov/01-meshes/perry.cpp -o CMakeFiles/perry.dir/perry.cpp.s

# Object files for target perry
perry_OBJECTS = \
"CMakeFiles/perry.dir/perry.cpp.o"

# External object files for target perry
perry_EXTERNAL_OBJECTS =

perry: CMakeFiles/perry.dir/perry.cpp.o
perry: CMakeFiles/perry.dir/build.make
perry: /usr/lib/x86_64-linux-gnu/libgmsh.so
perry: CMakeFiles/perry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laythe/miniscience-kalashnikov/01-meshes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable perry"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/perry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perry.dir/build: perry
.PHONY : CMakeFiles/perry.dir/build

CMakeFiles/perry.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/perry.dir/cmake_clean.cmake
.PHONY : CMakeFiles/perry.dir/clean

CMakeFiles/perry.dir/depend:
	cd /home/laythe/miniscience-kalashnikov/01-meshes/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laythe/miniscience-kalashnikov/01-meshes /home/laythe/miniscience-kalashnikov/01-meshes /home/laythe/miniscience-kalashnikov/01-meshes/build /home/laythe/miniscience-kalashnikov/01-meshes/build /home/laythe/miniscience-kalashnikov/01-meshes/build/CMakeFiles/perry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/perry.dir/depend

