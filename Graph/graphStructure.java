package Graph;

import java.util.ArrayList;

abstract class graphStructure {
    static class UnweightedEdge {
        int src, dest;

        UnweightedEdge(int src, int dest) {
            this.src = src;
            this.dest = dest;
        }

        @Override
        public String toString() {
            return "Edge[" + "src=" + src + ", dest=" + dest + ']';
        }
    }

    static class WeightedEdge {
        int src, dest, weight;

        WeightedEdge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "src - "+this.src;
        }

    }
    static void createGraph(ArrayList<WeightedEdge>[] graph) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new WeightedEdge(0, 1, 1));
        graph[0].add(new WeightedEdge(0, 2, 1));

        graph[1].add(new WeightedEdge(1, 0, 1));
        graph[1].add(new WeightedEdge(1, 3, 1));

        graph[2].add(new WeightedEdge(2, 0, 1));
        graph[2].add(new WeightedEdge(2, 4, 1));

        graph[3].add(new WeightedEdge(3, 1, 1));
        graph[3].add(new WeightedEdge(3, 4, 1));
        graph[3].add(new WeightedEdge(3, 5, 1));

        graph[4].add(new WeightedEdge(4, 2, 1));
        graph[4].add(new WeightedEdge(4, 3, 1));
        graph[4].add(new WeightedEdge(4, 5, 1));
        
        graph[5].add(new WeightedEdge(5, 3, 1));
        graph[5].add(new WeightedEdge(5, 4, 1));
        graph[5].add(new WeightedEdge(5, 6, 1));
        
        graph[6].add(new WeightedEdge(6, 5, 1));
    }
}
