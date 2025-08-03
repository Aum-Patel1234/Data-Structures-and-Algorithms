class TreeNode {
  private int val;
  private TreeNode left, right;

  TreeNode() {
    this.left = null;
    this.right = null;
  }

  TreeNode(int val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }

  public TreeNode getLeftNode() {
    return this.left;
  }

  public TreeNode getRightNode() {
    return this.right;
  }

  public int getVal() {
    return this.val;
  }

  public void setVal(int val) {
    // checks if any
    this.val = val;
  }

  public void setLeftNode(TreeNode node) {
    this.left = node;
  }

  public void setRightNode(TreeNode node) {
    this.right = node;
  }
}

class AVLTree {
  private TreeNode head;

  AVLTree() {
    head = null;
  }

  public void insert(int val) {
    this.head = insertVal(val, this.head);
  }

  private TreeNode insertVal(int val, TreeNode node) {
    if (node == null)
      return new TreeNode(val);

    if (val < node.getVal()) {
      node.setLeftNode(insertVal(val, node.getLeftNode()));
    } else {
      node.setRightNode(insertVal(val, node.getRightNode()));
    }

    return rotate(node);
  }

  private TreeNode rotate(TreeNode node) {
    if (height(node.getLeftNode()) - height(node.getRightNode()) > 1) {
      if (height(node.getLeftNode().getLeftNode()) - height(node.getLeftNode().getRightNode()) > 0)
        return rightRotate(node);
      else {
        node.setLeftNode(leftRotate(node.getLeftNode()));
        return rightRotate(node);
      }
    }
    if (height(node.getLeftNode()) - height(node.getRightNode()) < -1) {
      if (height(node.getRightNode().getRightNode()) - height(node.getRightNode().getLeftNode()) > 0)
        return leftRotate(node);
      else {
        node.setRightNode(rightRotate(node.getRightNode()));
        return leftRotate(node);
      }
    }
    return node;
  }

  private TreeNode rightRotate(TreeNode node) {
    TreeNode child = node.getLeftNode();
    TreeNode grandChild = child.getRightNode();
    child.setRightNode(node);
    node.setLeftNode(grandChild);
    return child;
  }

  private TreeNode leftRotate(TreeNode node) {
    TreeNode child = node.getRightNode();
    TreeNode grandChild = child.getLeftNode();
    child.setLeftNode(node);
    node.setRightNode(grandChild);
    return child;
  }

  public int getHeight() {
    return height(head);
  }

  private int height(TreeNode node) {
    if (node == null)
      return 0;
    int left = height(node.getLeftNode()), right = height(node.getRightNode());
    return Math.max(left, right) + 1;
  }

  public int head() {
    return this.head.getVal();
  }

  public void printTree() {
    printTree(this.head, 0);
  }

  private void printTree(TreeNode node, int level) {
    if (node == null)
      return;

    printTree(node.getRightNode(), level + 1);

    for (int i = 0; i < level; i++)
      System.out.print("    ");
    System.out.println(node.getVal());

    printTree(node.getLeftNode(), level + 1);
  }

  // NOTE: implement deleteNode
}

public class avl_practice {
  public static void main(String[] args) {
    AVLTree tree = new AVLTree();

    for (int i = 0; i < 10; i++) {
      tree.insert(i);
    }

    System.out.println(tree.getHeight());
    tree.printTree();
  }
}
