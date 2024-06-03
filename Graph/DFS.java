package Graph;

import java.util.ArrayList;
import java.util.List;

public class DFS extends graphStructure {
    public static void main(String[] args) {
        ArrayList<WeightedEdge>[] graph = new ArrayList[7];
        createGraph(graph);
        boolean[] visited = new boolean[graph.length];
        // System.out.println("DFS");
        // DepthFirstSearch(graph,graph[0].get(0).src,visited);

        // All Paths from Source to Destination
        List<List<Integer>> paths = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        visited[graph[0].get(0).src] = true;
        allPathsfromSourcetoDestination(graph, 5, 0, visited, paths, path);
        System.out.println(paths);
    }

    static void DepthFirstSearch(ArrayList<WeightedEdge>[] graph, int current, boolean[] visited) {
        if (visited[current]) {
            return;
        }
        System.out.println(current);
        visited[current] = true;
        for (int i = 0; i < graph[current].size(); i++) {
            WeightedEdge edge = graph[current].get(i);
            DepthFirstSearch(graph, edge.dest, visited);
        }
    }

    static void allPathsfromSourcetoDestination(ArrayList<WeightedEdge>[] graph, int target, int src,
            boolean[] visited, List<List<Integer>> paths, List<Integer> path) {
        if (src == target) {
            paths.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < graph[src].size(); i++) {
            WeightedEdge edge = graph[src].get(i);
            if (!visited[edge.dest]) {
                visited[edge.dest] = true;
                path.add(edge.dest);
                allPathsfromSourcetoDestination(graph, target, edge.dest, visited, paths, path);
                path.remove(path.size() - 1);
                visited[edge.dest] = false;
            }
        }
    }

}
