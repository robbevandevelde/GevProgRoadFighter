# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/thibaut/Documents/CLion-2018.2.4/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/thibaut/Documents/CLion-2018.2.4/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug"

# Include any dependencies generated for this target.
include GameLogic/CMakeFiles/LogicLib.dir/depend.make

# Include the progress variables for this target.
include GameLogic/CMakeFiles/LogicLib.dir/progress.make

# Include the compile flags for this target's objects.
include GameLogic/CMakeFiles/LogicLib.dir/flags.make

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.o: ../GameLogic/Source/Entities/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Entity.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Entity.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Entity.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.o: ../GameLogic/Source/Entities/PlayerCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/PlayerCar.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/PlayerCar.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/PlayerCar.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.o: ../GameLogic/Source/Entities/Car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Car.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Car.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Car.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.o: ../GameLogic/Source/Entities/PassingCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/PassingCar.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/PassingCar.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/PassingCar.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.o: ../GameLogic/Source/Entities/RacingCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/RacingCar.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/RacingCar.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/RacingCar.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.o: ../GameLogic/Source/Entities/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Bullet.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Bullet.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/Bullet.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.o: ../GameLogic/Source/Entities/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/World.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/World.cpp" > CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entities/World.cpp" -o CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.o: ../GameLogic/Source/RoadFighterGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/RoadFighterGame.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/RoadFighterGame.cpp" > CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/RoadFighterGame.cpp" -o CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.s

GameLogic/CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.o: GameLogic/CMakeFiles/LogicLib.dir/flags.make
GameLogic/CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.o: ../GameLogic/Source/Entity_Factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object GameLogic/CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entity_Factory.cpp"

GameLogic/CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entity_Factory.cpp" > CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.i

GameLogic/CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic/Source/Entity_Factory.cpp" -o CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.s

# Object files for target LogicLib
LogicLib_OBJECTS = \
"CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.o" \
"CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.o"

# External object files for target LogicLib
LogicLib_EXTERNAL_OBJECTS =

GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Entity.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PlayerCar.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Car.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/PassingCar.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/RacingCar.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/Bullet.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entities/World.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/RoadFighterGame.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/Source/Entity_Factory.cpp.o
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/build.make
GameLogic/libLogicLib.a: GameLogic/CMakeFiles/LogicLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libLogicLib.a"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && $(CMAKE_COMMAND) -P CMakeFiles/LogicLib.dir/cmake_clean_target.cmake
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LogicLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GameLogic/CMakeFiles/LogicLib.dir/build: GameLogic/libLogicLib.a

.PHONY : GameLogic/CMakeFiles/LogicLib.dir/build

GameLogic/CMakeFiles/LogicLib.dir/clean:
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" && $(CMAKE_COMMAND) -P CMakeFiles/LogicLib.dir/cmake_clean.cmake
.PHONY : GameLogic/CMakeFiles/LogicLib.dir/clean

GameLogic/CMakeFiles/LogicLib.dir/depend:
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/GameLogic" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/GameLogic/CMakeFiles/LogicLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : GameLogic/CMakeFiles/LogicLib.dir/depend

