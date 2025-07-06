class Trie {
  static class Node {
    Node[] nodes;
    boolean flag;

    Node() {
      nodes = new Node[26];
      flag = false;
    }

    boolean isEnd() {
      return flag;
    }

    Node get(int i) {
      return nodes[i];
    }

    Node assign(int i) {
      nodes[i] = new Node();
      return nodes[i];
    }
  }

  Node head;

  public Trie() {
    head = new Node();
  }

  public void insert(String word) {
    Node temp = head;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      Node curr = temp.get(idx);
      if (curr == null) {
        curr = temp.assign(idx);
      }
      temp = curr;
    }
    temp.flag = true;
  }

  public boolean search(String word) {
    Node temp = findNode(word);
    return temp != null && temp.flag;
  }

  public boolean startsWith(String prefix) {
    return findNode(prefix) != null;
  }

  private Node findNode(String s) {
    Node temp = head;
    for (int i = 0; i < s.length(); i++) {
      int idx = s.charAt(i) - 'a';
      Node curr = temp.get(idx);
      if (curr == null) {
        return null;
      }
      temp = curr;
    }
    return temp;
  }
}

public class trie {
  public static void main(String[] args) {
    Trie trie = new Trie();

    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("batman");

    // Test search function
    System.out.println("Search for 'apple': " + (trie.search("apple") ? "Found" : "Not Found"));
    System.out.println("Search for 'app': " + (trie.search("app") ? "Found" : "Not Found"));
    System.out.println("Search for 'bat': " + (trie.search("bat") ? "Found" : "Not Found"));
    System.out.println("Search for 'batman': " + (trie.search("batman") ? "Found" : "Not Found"));
    System.out.println("Search for 'batmobile': " + (trie.search("batmobile") ? "Found" : "Not Found"));

    // Test startsWith function
    System.out.println("Starts with 'app': " + (trie.startsWith("app") ? "Yes" : "No"));
    System.out.println("Starts with 'bat': " + (trie.startsWith("bat") ? "Yes" : "No"));
    System.out.println("Starts with 'batm': " + (trie.startsWith("batm") ? "Yes" : "No"));
    System.out.println("Starts with 'cat': " + (trie.startsWith("cat") ? "Yes" : "No"));
  }
}
