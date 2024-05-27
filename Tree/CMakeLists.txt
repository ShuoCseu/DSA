cmake_minimum_required(VERSION 3.0)
project(myproject)

# Include the directory containing header files
include_directories(include)

# Add the source files
set(SOURCES
    src/main.cpp
    src/Tree.cpp
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})