package Graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class DijkstrasAlgorithm extends graphStructure {
    static class Pair implements Comparable<Pair> {
        int src;
        int distance;

        Pair(int src, int distance) {
            this.src = src;
            this.distance = distance;
        }

        @Override
        public int compareTo(Pair o) {
            return this.distance - o.distance;
        }
    }

    static void createGraph(ArrayList<WeightedEdge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new WeightedEdge(0, 1, 2));
        graph[0].add(new WeightedEdge(0, 2, 4));

        graph[1].add(new WeightedEdge(1, 3, 7));
        graph[1].add(new WeightedEdge(1, 2, 1));

        graph[2].add(new WeightedEdge(2, 4, 3));

        graph[3].add(new WeightedEdge(3, 5, 1));

        graph[4].add(new WeightedEdge(4, 3, 2));
        graph[4].add(new WeightedEdge(4, 5, 5));
    }

    private static int[] dijkstraAlgorithm(ArrayList<WeightedEdge>[] graph,int src) {
        PriorityQueue<Pair> priorityQueue = new PriorityQueue<>();
        boolean[] visited = new boolean[graph.length];
        int[] distance = new int[graph.length];
        distance[src] = 0;
        
        for (int i = 0; i < distance.length; i++) {
            if(i != src){
                distance[i] = Integer.MAX_VALUE;
            }
        }
        
        // Time Complexity - O(E + ElogV)
        
        priorityQueue.offer(new Pair(src, 0));
        while (!priorityQueue.isEmpty()) {
            Pair current = priorityQueue.poll();
            if(!visited[current.src]){
                visited[current.src] = true;

                for (int i = 0; i < graph[current.src].size(); i++) {
                    WeightedEdge edge = graph[current.src].get(i);
                    int u = edge.src;
                    int v = edge.dest;
                    if(!visited[v] && distance[u] + edge.weight < distance [v]){
                        distance[v] = distance[u] + edge.weight;
                        priorityQueue.add(new Pair(v, distance[v]));
                    }
                }
            }
        }

        return distance;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = 6;
        ArrayList<WeightedEdge>[] graph = new ArrayList[V];
        createGraph(graph);
        System.out.println("Enter Source : ");
        int src = sc.nextInt();
        System.out.println(Arrays.toString(dijkstraAlgorithm(graph, src)));
        sc.close();
    }
}
