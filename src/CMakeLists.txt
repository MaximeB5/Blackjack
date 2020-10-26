# Ensures adding current source and build directory to the include path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Tell to CMake where our includes are
#include_directories(${CMAKE_SOURCE_DIR}/include)

# Get all sources (using recursivity)
file(GLOB_RECURSE PRJ_SOURCES *.cpp)

# Get all headers (using recursivity)
file(GLOB_RECURSE PRJ_HEADERS *.hpp)

# Create exec by giving him all sources and headers
add_executable(Blackjack ${PRJ_SOURCES} ${PRJ_HEADERS} "../main.cpp")
