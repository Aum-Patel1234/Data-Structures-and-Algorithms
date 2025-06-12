import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class bfs {
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
    breadthFistSearch(adj);
  }

  public static void breadthFistSearch(ArrayList<ArrayList<Integer>> adj) {
    boolean[] visited = new boolean[adj.size()];
    Queue<Integer> q = new LinkedList<>();
    q.offer(0);
    visited[0] = true;

    while (!q.isEmpty()) {
      int curr = q.poll();
      System.out.println(curr);

      for (int i = 0; i < adj.get(curr).size(); i++) {
        int val = adj.get(curr).get(i);
        if (!visited[val]) {
          visited[val] = true;
          q.offer(val);
        }
      }
    }
  }
}
