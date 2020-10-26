cmake_minimum_required(VERSION 3.10.0)

project(Blackjack)

# Ensures adding current source and build directory to the include path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Move the .exe into the Bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Make this a GUI application on Windows
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

# Add class headers and interfaces
FILE(GLOB_RECURSE IncludeFiles "include/*.hpp")
add_custom_target(headersinc SOURCES ${IncludeFiles})

FILE(GLOB_RECURSE InterfaceFiles "interface/*.hpp")
add_custom_target(headersint SOURCES ${InterfaceFiles})

# Tell to CMake where our sources are
add_subdirectory(src)