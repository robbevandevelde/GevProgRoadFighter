#setting cmake version and project name
cmake_minimum_required(VERSION 3.6)
project(GevProgRoadFighter)

set(CMAKE_CXX_STANDARD 14)
#extra compile flags to make srue code conventions are followed
#set(CMAKE_CXX_FLAGS "-Wall -Werror")

# run cmakelist in GameLogic
add_subdirectory(GameLogic)

# run cmakelist in SFMLconversion containing the sfml target
add_subdirectory(SFMLConversion)

# run cmakelist in Test containing the test target
add_subdirectory(Test)

