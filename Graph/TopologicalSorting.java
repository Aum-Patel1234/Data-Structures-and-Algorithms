package Graph;

import java.util.ArrayList;
import java.util.Stack;

import Graph.graphStructure.Edge;

public class TopologicalSorting {

    private static void topsort(ArrayList<Edge>[] graph) {
        boolean visited[] = new boolean[graph.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                topologicalSort(graph, i, visited, stack);
            }
        }
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + "  ");
        }
    }

    private static void topologicalSort(ArrayList<Edge>[] graph, int current, boolean[] visited, Stack<Integer> stack) {
        if (visited[current]) {
            return;
        }
        visited[current] = true;
        for (int i = 0; i < graph[i].size(); i++) {
            Edge edge = graph[current].get(i);
            if (!visited[edge.dest]) {
                topologicalSort(graph, edge.dest, visited, stack);
            }
        }
        stack.push(current);
    }

    static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[2].add(new Edge(2, 3));
        graph[3].add(new Edge(3, 1));
        graph[4].add(new Edge(4, 0));
        graph[4].add(new Edge(4, 1));
        graph[5].add(new Edge(5, 0));
        graph[5].add(new Edge(5, 2));
    }

    public static void main(String[] args) {
        int V = 6;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        topsort(graph);
    }
}
