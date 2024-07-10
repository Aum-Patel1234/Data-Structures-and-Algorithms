package Graph;

import java.util.ArrayList;
import java.util.Stack;

import Graph.graphStructure.Edge;

public class KosarajuAlgorithm {
    public static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        graph[1].add(new Edge(1, 3));
        graph[1].add(new Edge(1, 4));
        graph[2].add(new Edge(2, 1));
        graph[3].add(new Edge(3, 2));
        graph[4].add(new Edge(4, 5));
    }

    private static ArrayList<Edge>[] transposeGraph(ArrayList<Edge>[] graph) {
        ArrayList<Edge>[] transposedGraph = new ArrayList[graph.length];
        for (int i = 0; i < graph.length; i++) {
            transposedGraph[i] = new ArrayList<Edge>();
        }
        for (ArrayList<Edge> edges : graph) {
            for (Edge edge : edges) {
                transposedGraph[edge.dest].add(new Edge(edge.dest, edge.src));
            }
        }
        return transposedGraph;
    }

    private static void kosaraju(ArrayList<Edge>[] graph, int src) {
        int V = graph.length;
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[V];
        DepthfirstSearch(graph, stack, visited, 1);

        graph = transposeGraph(graph);
        ArrayList<ArrayList<Integer>> strongly_connected_components = new ArrayList<>();
        visited = new boolean[V];
        
        while(!stack.isEmpty()){
            int current = stack.pop();
            if(!visited[current]){
                ArrayList<Integer> scc = new ArrayList<>();
                dfs(graph, visited,scc,current);
                strongly_connected_components.add(scc);
            }
        }
        
        System.out.println(strongly_connected_components);
    }

    private static void dfs(ArrayList<Edge>[] graph, boolean[] visited,ArrayList<Integer> scc,int src) {
        visited[src] = true;
        scc.add(src);
        for (Edge edge : graph[src]) {
            if(!visited[edge.dest]){
                dfs(graph, visited, scc, edge.dest);
            }
        }
    }

    private static void DepthfirstSearch(ArrayList<Edge>[] graph, Stack<Integer> stack, boolean[] visited, int src) {
        visited[src] = true;
        for (Edge edge : graph[src]) {
            if (!visited[edge.dest]) {
                DepthfirstSearch(graph, stack, visited, edge.dest);
            }
        }
        stack.push(src);
    }

    public static void main(String[] args) {
        int V = 6;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        kosaraju(graph, 1);
        /*
         * Steps
         * 1. Get nodes in stack(toposort)
         * 2. Transpose the graph
         * 3. do DFS according to stack nodes on the transpose graph
         */
    }
}
