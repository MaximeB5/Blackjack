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
CMAKE_SOURCE_DIR = /home/maxime/Bureau/CppProjects/Blackjack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maxime/Bureau/CppProjects/Blackjack/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Blackjack.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Blackjack.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Blackjack.dir/flags.make

src/CMakeFiles/Blackjack.dir/card.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/card.cpp.o: ../src/card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Blackjack.dir/card.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/card.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/src/card.cpp

src/CMakeFiles/Blackjack.dir/card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/card.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/src/card.cpp > CMakeFiles/Blackjack.dir/card.cpp.i

src/CMakeFiles/Blackjack.dir/card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/card.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/src/card.cpp -o CMakeFiles/Blackjack.dir/card.cpp.s

src/CMakeFiles/Blackjack.dir/casinodealer.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/casinodealer.cpp.o: ../src/casinodealer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Blackjack.dir/casinodealer.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/casinodealer.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/src/casinodealer.cpp

src/CMakeFiles/Blackjack.dir/casinodealer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/casinodealer.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/src/casinodealer.cpp > CMakeFiles/Blackjack.dir/casinodealer.cpp.i

src/CMakeFiles/Blackjack.dir/casinodealer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/casinodealer.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/src/casinodealer.cpp -o CMakeFiles/Blackjack.dir/casinodealer.cpp.s

src/CMakeFiles/Blackjack.dir/deck.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/deck.cpp.o: ../src/deck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Blackjack.dir/deck.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/deck.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/src/deck.cpp

src/CMakeFiles/Blackjack.dir/deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/deck.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/src/deck.cpp > CMakeFiles/Blackjack.dir/deck.cpp.i

src/CMakeFiles/Blackjack.dir/deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/deck.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/src/deck.cpp -o CMakeFiles/Blackjack.dir/deck.cpp.s

src/CMakeFiles/Blackjack.dir/gameboard.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/gameboard.cpp.o: ../src/gameboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/Blackjack.dir/gameboard.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/gameboard.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/src/gameboard.cpp

src/CMakeFiles/Blackjack.dir/gameboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/gameboard.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/src/gameboard.cpp > CMakeFiles/Blackjack.dir/gameboard.cpp.i

src/CMakeFiles/Blackjack.dir/gameboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/gameboard.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/src/gameboard.cpp -o CMakeFiles/Blackjack.dir/gameboard.cpp.s

src/CMakeFiles/Blackjack.dir/humanplayer.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/humanplayer.cpp.o: ../src/humanplayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/Blackjack.dir/humanplayer.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/humanplayer.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/src/humanplayer.cpp

src/CMakeFiles/Blackjack.dir/humanplayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/humanplayer.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/src/humanplayer.cpp > CMakeFiles/Blackjack.dir/humanplayer.cpp.i

src/CMakeFiles/Blackjack.dir/humanplayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/humanplayer.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/src/humanplayer.cpp -o CMakeFiles/Blackjack.dir/humanplayer.cpp.s

src/CMakeFiles/Blackjack.dir/score.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/score.cpp.o: ../src/score.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/Blackjack.dir/score.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/score.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/src/score.cpp

src/CMakeFiles/Blackjack.dir/score.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/score.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/src/score.cpp > CMakeFiles/Blackjack.dir/score.cpp.i

src/CMakeFiles/Blackjack.dir/score.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/score.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/src/score.cpp -o CMakeFiles/Blackjack.dir/score.cpp.s

src/CMakeFiles/Blackjack.dir/__/main.cpp.o: src/CMakeFiles/Blackjack.dir/flags.make
src/CMakeFiles/Blackjack.dir/__/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/Blackjack.dir/__/main.cpp.o"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blackjack.dir/__/main.cpp.o -c /home/maxime/Bureau/CppProjects/Blackjack/main.cpp

src/CMakeFiles/Blackjack.dir/__/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blackjack.dir/__/main.cpp.i"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Bureau/CppProjects/Blackjack/main.cpp > CMakeFiles/Blackjack.dir/__/main.cpp.i

src/CMakeFiles/Blackjack.dir/__/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blackjack.dir/__/main.cpp.s"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Bureau/CppProjects/Blackjack/main.cpp -o CMakeFiles/Blackjack.dir/__/main.cpp.s

# Object files for target Blackjack
Blackjack_OBJECTS = \
"CMakeFiles/Blackjack.dir/card.cpp.o" \
"CMakeFiles/Blackjack.dir/casinodealer.cpp.o" \
"CMakeFiles/Blackjack.dir/deck.cpp.o" \
"CMakeFiles/Blackjack.dir/gameboard.cpp.o" \
"CMakeFiles/Blackjack.dir/humanplayer.cpp.o" \
"CMakeFiles/Blackjack.dir/score.cpp.o" \
"CMakeFiles/Blackjack.dir/__/main.cpp.o"

# External object files for target Blackjack
Blackjack_EXTERNAL_OBJECTS =

../bin/Blackjack: src/CMakeFiles/Blackjack.dir/card.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/casinodealer.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/deck.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/gameboard.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/humanplayer.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/score.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/__/main.cpp.o
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/build.make
../bin/Blackjack: src/CMakeFiles/Blackjack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maxime/Bureau/CppProjects/Blackjack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../../bin/Blackjack"
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Blackjack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Blackjack.dir/build: ../bin/Blackjack

.PHONY : src/CMakeFiles/Blackjack.dir/build

src/CMakeFiles/Blackjack.dir/clean:
	cd /home/maxime/Bureau/CppProjects/Blackjack/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Blackjack.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Blackjack.dir/clean

src/CMakeFiles/Blackjack.dir/depend:
	cd /home/maxime/Bureau/CppProjects/Blackjack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maxime/Bureau/CppProjects/Blackjack /home/maxime/Bureau/CppProjects/Blackjack/src /home/maxime/Bureau/CppProjects/Blackjack/build /home/maxime/Bureau/CppProjects/Blackjack/build/src /home/maxime/Bureau/CppProjects/Blackjack/build/src/CMakeFiles/Blackjack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Blackjack.dir/depend

