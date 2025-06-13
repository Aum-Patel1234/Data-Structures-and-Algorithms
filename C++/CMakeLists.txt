cmake_minimum_required(VERSION 4.0)
project(DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include all folders for headers
include_directories(
    ${CMAKE_SOURCE_DIR}/graph/make_graph
    ${CMAKE_SOURCE_DIR}/graph
    ${CMAKE_SOURCE_DIR}/implementation
    ${CMAKE_SOURCE_DIR}/examples
    ${CMAKE_SOURCE_DIR}/imp
)

# Add make_graph as a library
add_library(make_graph_lib
    graph/make_graph/make_graph.cpp
)

# Collect all main files (you can add more if you want)
add_executable(dfs graph/dfs.cpp)
target_link_libraries(dfs PRIVATE make_graph_lib)

add_executable(bfs graph/bfs.cpp)
target_link_libraries(bfs PRIVATE make_graph_lib)

add_executable(pair_example examples/pair_eg.cpp)

add_executable(linked_list_example implementation/linked_list.cpp)
