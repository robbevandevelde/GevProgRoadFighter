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
CMAKE_COMMAND = /home/thibaut/Documents/CLion-2018.3/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/thibaut/Documents/CLion-2018.3/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug"

# Include any dependencies generated for this target.
include SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/depend.make

# Include the progress variables for this target.
include SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/progress.make

# Include the compile flags for this target's objects.
include SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/main.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/main.cpp.o: ../SFMLConversion/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/main.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/main.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/main.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/main.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/main.cpp" > CMakeFiles/GevProgRoadFighter.dir/main.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/main.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/main.cpp" -o CMakeFiles/GevProgRoadFighter.dir/main.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.o: ../SFMLConversion/Source/SFMLRoadFighter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/SFMLRoadFighter.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/SFMLRoadFighter.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/SFMLRoadFighter.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.o: ../SFMLConversion/Source/entities/SFMLPlayerCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLPlayerCar.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLPlayerCar.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLPlayerCar.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.o: ../SFMLConversion/Source/entities/SFMLEntitySprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLEntitySprite.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLEntitySprite.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLEntitySprite.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.o: ../SFMLConversion/Source/Transformation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/Transformation.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/Transformation.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/Transformation.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.o: ../SFMLConversion/Source/SFML_Entity_Factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/SFML_Entity_Factory.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/SFML_Entity_Factory.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/SFML_Entity_Factory.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.o: ../SFMLConversion/Source/entities/SFMLWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLWorld.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLWorld.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLWorld.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.o: ../SFMLConversion/Source/entities/SFMLRacingCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLRacingCar.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLRacingCar.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLRacingCar.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.o: ../SFMLConversion/Source/entities/SFMLBonusCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLBonusCar.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLBonusCar.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLBonusCar.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.o: ../SFMLConversion/Source/entities/SFMLPassingCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLPassingCar.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLPassingCar.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLPassingCar.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.o: ../SFMLConversion/Source/entities/SFMLBullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLBullet.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLBullet.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLBullet.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.s

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.o: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/flags.make
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.o: ../SFMLConversion/Source/entities/SFMLEnd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.o"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.o -c "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLEnd.cpp"

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.i"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLEnd.cpp" > CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.i

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.s"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion/Source/entities/SFMLEnd.cpp" -o CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.s

# Object files for target GevProgRoadFighter
GevProgRoadFighter_OBJECTS = \
"CMakeFiles/GevProgRoadFighter.dir/main.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.o" \
"CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.o"

# External object files for target GevProgRoadFighter
GevProgRoadFighter_EXTERNAL_OBJECTS =

SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/main.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFMLRoadFighter.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPlayerCar.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEntitySprite.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/Transformation.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/SFML_Entity_Factory.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLWorld.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLRacingCar.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBonusCar.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLPassingCar.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLBullet.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/Source/entities/SFMLEnd.cpp.o
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/build.make
SFMLConversion/GevProgRoadFighter: GameLogic/libGLL.a
SFMLConversion/GevProgRoadFighter: /usr/lib/x86_64-linux-gnu/libsfml-system.so
SFMLConversion/GevProgRoadFighter: /usr/lib/x86_64-linux-gnu/libsfml-window.so
SFMLConversion/GevProgRoadFighter: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
SFMLConversion/GevProgRoadFighter: SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable GevProgRoadFighter"
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GevProgRoadFighter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/build: SFMLConversion/GevProgRoadFighter

.PHONY : SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/build

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/clean:
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" && $(CMAKE_COMMAND) -P CMakeFiles/GevProgRoadFighter.dir/cmake_clean.cmake
.PHONY : SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/clean

SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/depend:
	cd "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/SFMLConversion" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion" "/home/thibaut/CLionProjects/gevorderd programmeren/GevProgRoadFighter/cmake-build-debug/SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : SFMLConversion/CMakeFiles/GevProgRoadFighter.dir/depend

