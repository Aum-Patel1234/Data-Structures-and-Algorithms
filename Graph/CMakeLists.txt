cmake_minimum_required(VERSION 3.21)

project(GraphAlgorithms LANGUAGES CXX)

# -----------------------------
# C++ Standard
# -----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# Core Graph Library
# -----------------------------
add_library(graph_core
    src/disjoint_set.cpp
)

target_include_directories(graph_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

# -----------------------------
# Executables (MANUAL)
# -----------------------------

add_executable(bellman_ford src/bellman_ford.cpp)
target_link_libraries(bellman_ford PRIVATE graph_core)

add_executable(bfs src/bfs.cpp)
target_link_libraries(bfs PRIVATE graph_core)

add_executable(bipartite src/bipartite.cpp)
target_link_libraries(bipartite PRIVATE graph_core)

add_executable(detect_cycle_graph src/detect_cycle_graph.cpp)
target_link_libraries(detect_cycle_graph PRIVATE graph_core)

add_executable(dfs src/dfs.cpp)
target_link_libraries(dfs PRIVATE graph_core)

add_executable(dijkstra src/dijkstra.cpp)
target_link_libraries(dijkstra PRIVATE graph_core)

# add_executable(disjoint_set src/disjoint_set.cpp)
# target_link_libraries(disjoint_set PRIVATE graph_core)

add_executable(floyd_warshall src/floyd_warshall.cpp)
target_link_libraries(floyd_warshall PRIVATE graph_core)

add_executable(impq src/impq.cpp)
target_link_libraries(impq PRIVATE graph_core)

add_executable(kahnAlgo src/kahnAlgo.cpp)
target_link_libraries(kahnAlgo PRIVATE graph_core)

add_executable(kruskal src/kruskal.cpp)
target_link_libraries(kruskal PRIVATE graph_core)

add_executable(prim src/prim.cpp)
target_link_libraries(prim PRIVATE graph_core)

add_executable(shortest_path_dag src/shortest_path_dag.cpp)
target_link_libraries(shortest_path_dag PRIVATE graph_core)

add_executable(shortest_undirected_path src/shortest_undirected_path.cpp)
target_link_libraries(shortest_undirected_path PRIVATE graph_core)

add_executable(topoSort src/topoSort.cpp)
target_link_libraries(topoSort PRIVATE graph_core)
