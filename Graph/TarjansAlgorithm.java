package Graph;

import java.util.ArrayList;

import Graph.graphStructure.Edge;

public class TarjansAlgorithm {
    public static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        graph[0].add(new Edge(0, 1));
        graph[0].add(new Edge(0, 3));

        graph[1].add(new Edge(1, 0));
        graph[1].add(new Edge(1, 2));

        graph[2].add(new Edge(2, 1));
        graph[2].add(new Edge(2, 4));
        graph[2].add(new Edge(2, 3));
        graph[2].add(new Edge(2, 6));

        graph[3].add(new Edge(3, 0));
        graph[3].add(new Edge(3, 2));
        graph[3].add(new Edge(3, 5));

        graph[4].add(new Edge(4, 2));

        graph[5].add(new Edge(5, 3));
        graph[5].add(new Edge(5, 6));

        graph[6].add(new Edge(6, 2));
        graph[6].add(new Edge(6, 5));
    }

    public static void TarjansAlgorithmForBridges(ArrayList<Edge> graph[], int V) {
        boolean[] visited = new boolean[V];
        int[] discovery_time = new int[V];
        int[] lowest_discovery_time = new int[V];
        int[] time = {0}; // Array to pass time by reference

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(graph, discovery_time, lowest_discovery_time, i, -1, visited, time);
            }
        }
    }

    private static void dfs(ArrayList<Edge>[] graph, int[] discovery_time, int[] lowest_discovery_time, int curr, int parent, boolean[] visited, int[] time) {
        visited[curr] = true;
        discovery_time[curr] = lowest_discovery_time[curr] = ++time[0];

        for (Edge edge : graph[curr]) {
            if (edge.dest == parent) {
                continue;
            }
            if (visited[edge.dest]) {
                lowest_discovery_time[curr] = Math.min(lowest_discovery_time[curr], discovery_time[edge.dest]);
            } else {
                dfs(graph, discovery_time, lowest_discovery_time, edge.dest, curr, visited, time);
                lowest_discovery_time[curr] = Math.min(lowest_discovery_time[curr], lowest_discovery_time[edge.dest]);
                if (discovery_time[curr] < lowest_discovery_time[edge.dest]) {
                    System.out.println("Bridge at: " + curr + " ---- " + edge.dest);
                }
            }
        }
    }

    public static void main(String[] args) {
        int V = 7;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        TarjansAlgorithmForBridges(graph, V);
    }
}
