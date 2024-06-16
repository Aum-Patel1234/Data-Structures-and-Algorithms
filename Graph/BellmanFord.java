package Graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BellmanFord extends graphStructure {
    static void createGraph(ArrayList<WeightedEdge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new WeightedEdge(0, 1, -1));
        graph[0].add(new WeightedEdge(0, 2, 4));

        graph[1].add(new WeightedEdge(1, 2, 3));
        graph[1].add(new WeightedEdge(1, 3, 2));
        graph[1].add(new WeightedEdge(1, 4, 2));

        graph[3].add(new WeightedEdge(3, 2, 5));
        graph[3].add(new WeightedEdge(3, 1, 1));

        graph[4].add(new WeightedEdge(4, 3, -3));

    }

    public static int[] BellmanFordAlgoritm(ArrayList<WeightedEdge>[] graph, int src) {
        int V = graph.length;
        int[] shortestDistance = new int[V];
        Arrays.fill(shortestDistance, Integer.MAX_VALUE);
        shortestDistance[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            // finding shortest path for V_1 tims
            for (int j = 0; j < graph.length; j++) {
                for (int k = 0; k < graph[j].size(); k++) {
                    WeightedEdge edge = graph[j].get(k);
                    int u = edge.src;
                    int v = edge.dest;
                    if (shortestDistance[u] != Integer.MAX_VALUE && shortestDistance[u] + edge.weight < shortestDistance[v]) {
                        shortestDistance[v] = shortestDistance[u] + edge.weight;
                    }
                }
            }
        }

        for (int j = 0; j < graph.length; j++) {
            for (int k = 0; k < graph[j].size(); k++) {
                WeightedEdge edge = graph[j].get(k);
                int u = edge.src;
                int v = edge.dest;
                if (shortestDistance[u] != Integer.MAX_VALUE && shortestDistance[u] + edge.weight < shortestDistance[v]) {
                    System.out.println("Negative Weight founded !!");
                    return null;
                }
            }
        }

        return shortestDistance;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = 6;
        ArrayList<WeightedEdge>[] graph = new ArrayList[V];
        createGraph(graph);
        System.out.println("Enter Source : ");
        int src = sc.nextInt();
        System.out.println(Arrays.toString(BellmanFordAlgoritm(graph, src)));
        sc.close();
    }

}
