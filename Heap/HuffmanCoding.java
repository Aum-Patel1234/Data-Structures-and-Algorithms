
import java.util.HashMap;
import java.util.Map;

public class HuffmanCoding {
    HashMap<Character, String> encoder;
    HashMap<String, Character> decoder;

    private class Node implements Comparable<Node> {
        int cost;
        char data;
        Node left, right;

        Node(char data, int cost) {
            this.cost = cost;
            this.data = data;
            this.left = null;
            this.right = null;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    public HuffmanCoding(String feeder) throws Exception {
        HashMap<Character, Integer> fmap = new HashMap<>();

        for (int i = 0; i < feeder.length(); i++) {
            char ch = feeder.charAt(i);
            if (fmap.containsKey(ch)) {
                fmap.put(ch, fmap.get(ch) + 1);
            } else {
                fmap.put(ch, 1);
            }
        }

        Heap<Node> minheap = new Heap<>();
        for (Map.Entry<Character, Integer> entry : fmap.entrySet()) {
            minheap.insert(new Node(entry.getKey(), entry.getValue()));
        }

        while (minheap.size() != 1) {
            Node node1 = minheap.remove();
            Node node2 = minheap.remove();

            Node temp = new Node('\0', node1.cost + node2.cost);
            temp.left = node1;
            temp.right = node2;

            minheap.insert(temp);
        }

        Node top = minheap.remove();

        this.encoder = new HashMap<>();
        this.decoder = new HashMap<>();

        this.initEncoderDecoder(top, "");
    }

    private void initEncoderDecoder(Node node, String osf) { // osf = output so far
        if (node == null) {
            return;
        }
        if (node.left == null && node.right == null) {
            this.encoder.put(node.data, osf);
            this.decoder.put(osf, node.data);
        }
        initEncoderDecoder(node.left, osf + "0");
        initEncoderDecoder(node.right, osf + "1");
    }

    public String encode(String str) {
        String ans = "";
        for (int i = 0; i < str.length(); i++) {
            ans += this.encoder.get(str.charAt(i));
        }
        return ans;
    }

    public String decode(String codedString) {
        String key = "";
        String ans = "";
        for (int i = 0; i < codedString.length(); i++) {
            key = key + codedString.charAt(i);
            if (decoder.containsKey(key)) {
                ans = ans + decoder.get(key);
                key = "";
            }
        }
        return ans;
    }

    public static void main(String[] args) throws Exception{
        String str = "abbccda";
        HuffmanCoding hf = new HuffmanCoding(str);
        String cs = hf.encode(str);
        System.out.println(cs);
        String dc = hf.decode(cs);
        System.out.println(dc);

    // Bitset can be used: like an array but with a bit at each index
    }
}
