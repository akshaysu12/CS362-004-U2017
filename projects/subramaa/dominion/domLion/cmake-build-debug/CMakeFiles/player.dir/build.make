# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/player.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/player.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/player.dir/flags.make

CMakeFiles/player.dir/dominion.c.o: CMakeFiles/player.dir/flags.make
CMakeFiles/player.dir/dominion.c.o: ../dominion.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/player.dir/dominion.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/player.dir/dominion.c.o   -c /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/dominion.c

CMakeFiles/player.dir/dominion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/player.dir/dominion.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/dominion.c > CMakeFiles/player.dir/dominion.c.i

CMakeFiles/player.dir/dominion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/player.dir/dominion.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/dominion.c -o CMakeFiles/player.dir/dominion.c.s

CMakeFiles/player.dir/dominion.c.o.requires:

.PHONY : CMakeFiles/player.dir/dominion.c.o.requires

CMakeFiles/player.dir/dominion.c.o.provides: CMakeFiles/player.dir/dominion.c.o.requires
	$(MAKE) -f CMakeFiles/player.dir/build.make CMakeFiles/player.dir/dominion.c.o.provides.build
.PHONY : CMakeFiles/player.dir/dominion.c.o.provides

CMakeFiles/player.dir/dominion.c.o.provides.build: CMakeFiles/player.dir/dominion.c.o


CMakeFiles/player.dir/player.c.o: CMakeFiles/player.dir/flags.make
CMakeFiles/player.dir/player.c.o: ../player.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/player.dir/player.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/player.dir/player.c.o   -c /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/player.c

CMakeFiles/player.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/player.dir/player.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/player.c > CMakeFiles/player.dir/player.c.i

CMakeFiles/player.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/player.dir/player.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/player.c -o CMakeFiles/player.dir/player.c.s

CMakeFiles/player.dir/player.c.o.requires:

.PHONY : CMakeFiles/player.dir/player.c.o.requires

CMakeFiles/player.dir/player.c.o.provides: CMakeFiles/player.dir/player.c.o.requires
	$(MAKE) -f CMakeFiles/player.dir/build.make CMakeFiles/player.dir/player.c.o.provides.build
.PHONY : CMakeFiles/player.dir/player.c.o.provides

CMakeFiles/player.dir/player.c.o.provides.build: CMakeFiles/player.dir/player.c.o


CMakeFiles/player.dir/interface.c.o: CMakeFiles/player.dir/flags.make
CMakeFiles/player.dir/interface.c.o: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/player.dir/interface.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/player.dir/interface.c.o   -c /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/interface.c

CMakeFiles/player.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/player.dir/interface.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/interface.c > CMakeFiles/player.dir/interface.c.i

CMakeFiles/player.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/player.dir/interface.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/interface.c -o CMakeFiles/player.dir/interface.c.s

CMakeFiles/player.dir/interface.c.o.requires:

.PHONY : CMakeFiles/player.dir/interface.c.o.requires

CMakeFiles/player.dir/interface.c.o.provides: CMakeFiles/player.dir/interface.c.o.requires
	$(MAKE) -f CMakeFiles/player.dir/build.make CMakeFiles/player.dir/interface.c.o.provides.build
.PHONY : CMakeFiles/player.dir/interface.c.o.provides

CMakeFiles/player.dir/interface.c.o.provides.build: CMakeFiles/player.dir/interface.c.o


CMakeFiles/player.dir/rngs.c.o: CMakeFiles/player.dir/flags.make
CMakeFiles/player.dir/rngs.c.o: ../rngs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/player.dir/rngs.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/player.dir/rngs.c.o   -c /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/rngs.c

CMakeFiles/player.dir/rngs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/player.dir/rngs.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/rngs.c > CMakeFiles/player.dir/rngs.c.i

CMakeFiles/player.dir/rngs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/player.dir/rngs.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/rngs.c -o CMakeFiles/player.dir/rngs.c.s

CMakeFiles/player.dir/rngs.c.o.requires:

.PHONY : CMakeFiles/player.dir/rngs.c.o.requires

CMakeFiles/player.dir/rngs.c.o.provides: CMakeFiles/player.dir/rngs.c.o.requires
	$(MAKE) -f CMakeFiles/player.dir/build.make CMakeFiles/player.dir/rngs.c.o.provides.build
.PHONY : CMakeFiles/player.dir/rngs.c.o.provides

CMakeFiles/player.dir/rngs.c.o.provides.build: CMakeFiles/player.dir/rngs.c.o


# Object files for target player
player_OBJECTS = \
"CMakeFiles/player.dir/dominion.c.o" \
"CMakeFiles/player.dir/player.c.o" \
"CMakeFiles/player.dir/interface.c.o" \
"CMakeFiles/player.dir/rngs.c.o"

# External object files for target player
player_EXTERNAL_OBJECTS =

player: CMakeFiles/player.dir/dominion.c.o
player: CMakeFiles/player.dir/player.c.o
player: CMakeFiles/player.dir/interface.c.o
player: CMakeFiles/player.dir/rngs.c.o
player: CMakeFiles/player.dir/build.make
player: CMakeFiles/player.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable player"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/player.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/player.dir/build: player

.PHONY : CMakeFiles/player.dir/build

CMakeFiles/player.dir/requires: CMakeFiles/player.dir/dominion.c.o.requires
CMakeFiles/player.dir/requires: CMakeFiles/player.dir/player.c.o.requires
CMakeFiles/player.dir/requires: CMakeFiles/player.dir/interface.c.o.requires
CMakeFiles/player.dir/requires: CMakeFiles/player.dir/rngs.c.o.requires

.PHONY : CMakeFiles/player.dir/requires

CMakeFiles/player.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/player.dir/cmake_clean.cmake
.PHONY : CMakeFiles/player.dir/clean

CMakeFiles/player.dir/depend:
	cd /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug /Users/akshaysubramanian/GitHub/CS362-004-U2017/projects/subramaa/dominion/domLion/cmake-build-debug/CMakeFiles/player.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/player.dir/depend

