package Graph;

import java.util.ArrayList;
import java.util.PriorityQueue;

import Graph.graphStructure.WeightedEdge;;

public class PrimsAlgorithm {
    static class Pair implements Comparable<Pair>{
        int src,weight;
        Pair(int src,int weight){
            this.src = src;
            this.weight = weight;
        }

        @Override
        public int compareTo(Pair o) {
            return this.weight - o.weight;
        }
    }
    static void createGraph(ArrayList<WeightedEdge> graph[]) {
        for(int i=0; i<graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new WeightedEdge(0, 1, 10));
        graph[0].add(new WeightedEdge(0, 2, 15));
        graph[0].add(new WeightedEdge(0, 3, 30));

        graph[1].add(new WeightedEdge(1, 0, 10));
        graph[1].add(new WeightedEdge(1, 3, 40));

        graph[2].add(new WeightedEdge(2, 0, 15));
        graph[2].add(new WeightedEdge(2, 3, 50));

        graph[3].add(new WeightedEdge(3, 1, 40));
        graph[3].add(new WeightedEdge(3, 2, 50));
    }

    private static int PrimsAlgorithmToFindMST(ArrayList<WeightedEdge>[] graph, int src) {
        int V = graph.length;
        int cost = 0;
        PriorityQueue<Pair> priorityQueue = new PriorityQueue<>();
        boolean[] visited = new boolean[V];

        priorityQueue.offer(new Pair(src, 0));
        while (!priorityQueue.isEmpty()) {
            Pair pair = priorityQueue.poll();
            if(!visited[pair.src]){
                visited[pair.src] = true;
                cost += pair.weight;

                for (int i = 0; i < graph[pair.src].size(); i++) {
                    WeightedEdge edge = graph[pair.src].get(i);
                    if(!visited[edge.dest]){
                        priorityQueue.offer(new Pair(edge.dest, edge.weight));
                    }
                }
            }
        }

        return cost;
    }

    public static void main(String[] args) {
        int V = 4;
        ArrayList<WeightedEdge>[] graph = new ArrayList[V];
        createGraph(graph);
        System.out.println(PrimsAlgorithmToFindMST(graph,0));
    }
}
