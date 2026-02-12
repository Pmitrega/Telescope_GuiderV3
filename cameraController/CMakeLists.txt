# CMake minimum version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Telescope_GuiderV3)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(inc)

# Define source files using set()
set(SOURCES 
            src/cameraController.cpp
            src/logger.cpp)

# Add executable
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# Link libraries (if any)
# target_link_libraries(${PROJECT_NAME} library_name)