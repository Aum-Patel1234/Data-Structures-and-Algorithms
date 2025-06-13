
import java.util.ArrayList;

public class dfs {
  public static void main(String[] args) {
    // Dummy graph as an edge list
    int[][] edges = {
        { 0, 1 },
        { 0, 2 },
        { 1, 3 },
        { 1, 4 },
        { 2, 5 },
        { 2, 6 }
    };

    int numNodes = 7;
    ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    for (int i = 0; i < numNodes; i++) {
      adj.add(new ArrayList<>());
    }

    for (int[] edge : edges) {
      adj.get(edge[0]).add(edge[1]);
      adj.get(edge[1]).add(edge[0]); // undirected graph
    }

    for (int i = 0; i < numNodes; i++) {
      System.out.print(i + " -> ");
      for (int neighbor : adj.get(i)) {
        System.out.print(neighbor + " ");
      }
      System.out.println();
    }

    System.out.println();
    ArrayList<Integer> dfs = depthFistSearch(adj);
    System.out.println(dfs.toString());
  }

  public static ArrayList<Integer> depthFistSearch(ArrayList<ArrayList<Integer>> adj) {
    ArrayList<Integer> dfs = new ArrayList<>();
    boolean[] visited = new boolean[adj.size()];
    helper(adj, dfs, visited, 0);
    return dfs;
  }

  private static void helper(ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> dfs, boolean[] visited, int curr) {
    dfs.add(curr);
    visited[curr] = true;

    ArrayList<Integer> cl = adj.get(curr);
    for (int i = 0; i < cl.size(); i++) {
      int node = cl.get(i);
      if (!visited[node]) {
        helper(adj, dfs, visited, node);
      }
    }
  }
}
