cmake_minimum_required(VERSION 4.0)

# Project name
project(DSABasics)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all .cpp files in this folder (except main.cpp if you want)
file(GLOB SOURCES "*.cpp")

# Create one executable per .cpp file
foreach(source ${SOURCES})
    # Get the file name without extension
    get_filename_component(exec_name ${source} NAME_WE)

    # Add executable
    add_executable(${exec_name} ${source})
endforeach()
