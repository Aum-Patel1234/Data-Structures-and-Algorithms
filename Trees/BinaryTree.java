package Trees;

import java.util.Scanner;

public class BinaryTree {
    class Node{
        int val;
        Node left;
        Node right;
        Node(int val){
            this.val=val;
        }
    }
    private Node root;
    public void insert(Scanner sc){
        System.out.println("Enter the root node:");
        int val=sc.nextInt();
        root=new Node(val);
        insertRemaining(sc,root);
    }

    private void insertRemaining(Scanner sc, Node node) {
        System.out.println("Do you want to enter left node of the given root node " + node.val);
        boolean left=sc.nextBoolean();
        if(left){
            System.out.println("Enter the value of the left node:");
            int val=sc.nextInt();
            node.left=new Node(val);
            insertRemaining(sc,node.left);
        }
        System.out.println("Do you want to enter right node of the given root node " + node.val);
        boolean right=sc.nextBoolean();
        if(right){
            System.out.println("Enter the value of the right node:");
            int val=sc.nextInt();
            node.right=new Node(val);
            insertRemaining(sc,node.right);
        }
    }
    public void display(){
        display(this.root," ");
    }
    public void display(Node root,String indent){
        if(root == null){
            return;
        }
        display(root.left,indent+ "\t");
        System.out.println(indent + root.val );
        display(root.right,indent+ "\t");
    }
    public void prettyDisplay() {
        prettyDisplay(root, 0);
    }

    private void prettyDisplay(Node node, int level) {
        if (node == null) {
            return;
        }

        prettyDisplay(node.right, level + 1);

        if (level != 0) {
            for (int i = 0; i < level - 1; i++) {
                System.out.print("|\t\t");
            }
            System.out.println("|------->" + node.val);
        } else {
            System.out.println(node.val);
        }
        prettyDisplay(node.left, level + 1);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BinaryTree tree=new BinaryTree();
        tree.insert(sc);
//        tree.display();
        tree.prettyDisplay();
    }
}
