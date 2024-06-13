package Graph;

import java.util.ArrayList;

import Graph.graphStructure.Edge;

public class CycleDetection {
    public static boolean isCyclicDirected(ArrayList<Edge>[] graph, int curr, boolean vis[], boolean stack[]) {
        vis[curr] = true;
        stack[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
            Edge e = graph[curr].get(i);
            if (stack[e.dest]) { // cycle exists
                return true;
            } else if (!vis[e.dest] && isCyclicDirected(graph, e.dest, vis, stack)) {
                return true;
            }
        }
        stack[curr] = false;
        return false;
    }

    private static boolean isCyclicUndirected(ArrayList<Edge>[] graph, boolean[] visited, int parent, int curr) {
        visited[curr] = true;

        for (int i = 0; i < graph[curr].size(); i++) {
            Edge e = graph[curr].get(i);
            if (!visited[e.dest]) {
                if (isCyclicUndirected(graph, visited, curr, e.dest)) {
                    return true;
                }
            } else if (e.dest != parent) {
                return true;
            }
        }
        return false;
    }

    public static boolean isCyclic(ArrayList<Edge>[] graph, boolean vis[]) {
        for (int i = 0; i < graph.length; i++) {
            if (!vis[i]) {
                if (isCyclicUndirected(graph, vis, -1, i)) {
                    return true;
                }
            }
        }
        return false;
    }

    static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new Edge(0, 2));

        graph[1].add(new Edge(1, 0));

        graph[2].add(new Edge(2, 3));

        graph[3].add(new Edge(3, 0));
    }

    static void createUndirectedGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new Edge(0, 1));
        graph[0].add(new Edge(0, 2));
        graph[0].add(new Edge(0, 3));

        graph[1].add(new Edge(1, 0));
        graph[1].add(new Edge(1, 2));

        graph[2].add(new Edge(2, 0));
        graph[2].add(new Edge(2, 1));

        graph[3].add(new Edge(3, 0));
        graph[3].add(new Edge(3, 4));

        graph[4].add(new Edge(4, 3));
    }

    public static boolean isCyclic(ArrayList<Edge>[] graph) {
        boolean vis[] = new boolean[graph.length];
        for (int i = 0; i < graph.length; i++) {
            if (!vis[i] ) {
                boolean cycle = isCyclicDirected(graph, i, vis, new boolean[vis.length]);
                if (cycle) {
                    return true;
                }
            }
        }
        return false;
    }


    public static void main(String args[]) {
        // int V = 5;
        // ArrayList<Edge> graph[] = new ArrayList[V];
        // createUndirectedGraph(graph);
        // System.out.println(isCyclic(graph, new boolean[V]));

        int V = 5;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);

        System.out.println(isCyclic(graph));
    }
}
