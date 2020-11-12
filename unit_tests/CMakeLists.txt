cmake_minimum_required(VERSION 3.10.0)

project(BlackjackTests)

# Set the C++ version required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensures adding current source and build directory to the include path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Move the .exe into the Bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Create the executable
add_executable(BlackjackTests
		blackjacktests.cpp
		../src/card.cpp
		../src/casinodealer.cpp
		../src/deck.cpp
		../src/gameboard.cpp
		../src/humanplayer.cpp
		../src/score.cpp)