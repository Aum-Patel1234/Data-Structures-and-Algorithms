cmake_minimum_required(VERSION 4.0)

project(GraphAlgorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# --- Directory Configuration ---
# Tell CMake where to find your header files (.h, .hpp). This allows your .cpp
# files to use #include "my_header.h" to import functions and classes.
include_directories(include)

# Find all .cpp files within the 'src' directory
file(GLOB SOURCE_FILES "src/*.cpp")

foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the name of the file without the path or extension (e.g., "src/bfs.cpp" -> "bfs")
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)

    # Create an executable with that name from the current source file
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

    # MODERN CMAKE: Apply the include directory to the specific target.
    # This is better than the global include_directories().
    target_include_directories(${EXECUTABLE_NAME} PRIVATE include)
    
    # Optional: A message to show which executables are being created
    message(STATUS "Creating executable: ${EXECUTABLE_NAME}")
endforeach()
