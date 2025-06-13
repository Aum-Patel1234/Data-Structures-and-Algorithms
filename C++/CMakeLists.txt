cmake_minimum_required(VERSION 4.0)
project(DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1) Place all executables in the build/ folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 2) Header search paths
include_directories(
    ${CMAKE_SOURCE_DIR}/graph/make_graph
    ${CMAKE_SOURCE_DIR}/graph
    ${CMAKE_SOURCE_DIR}/implementation
    ${CMAKE_SOURCE_DIR}/examples
    ${CMAKE_SOURCE_DIR}/imp
)

# 3) Build the graph‑construction library
add_library(make_graph_lib
    graph/make_graph/make_graph.cpp
)

# 4) Grab every .cpp under the project
file(GLOB_RECURSE ALL_CPP
     RELATIVE ${CMAKE_SOURCE_DIR}
     "*.cpp"
)

# 5) For each .cpp, if it has main(), build an executable
foreach(SRC IN LISTS ALL_CPP)
    # Skip the library source
    if(SRC MATCHES "^graph/make_graph/make_graph\\.cpp$")
        continue()
    endif()

    # Read file contents and check for a main()
    file(READ ${CMAKE_SOURCE_DIR}/${SRC} CONTENTS)
    string(FIND "${CONTENTS}" "main(" HAS_MAIN)

    if(HAS_MAIN EQUAL -1)
        # no main() → skip
        continue()
    endif()

    # Derive exe name (filename without extension)
    get_filename_component(EXE_NAME ${SRC} NAME_WE)

    # Build it
    add_executable(${EXE_NAME} ${SRC})

    # If it's in graph/, link the graph lib
    if(SRC MATCHES "^graph/.*\\.cpp$")
        target_link_libraries(${EXE_NAME} PRIVATE make_graph_lib)
    endif()
endforeach()

