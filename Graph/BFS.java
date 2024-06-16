package Graph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BFS extends graphStructure {
    public static void main(String[] args) {
        ArrayList<WeightedEdge>[] graph = new ArrayList[7];
        createGraph(graph);
        BreadthFirstSearch(graph);
    }

    static void BreadthFirstSearch(ArrayList<WeightedEdge>[] graph) {
        boolean visited[] = new boolean[graph.length];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0); // Source = 0

        while (!queue.isEmpty()) {
            int current = queue.poll();
            if(!visited[current]){
                System.out.println(current);
                visited[current] = true;

                for (int i = 0; i < graph[current].size(); i++) {
                    WeightedEdge edge = graph[current].get(i);
                    queue.offer(edge.dest);
                }
            }
        }
    }

}
