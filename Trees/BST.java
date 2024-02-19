package Trees;

import java.util.Scanner;

public class BST {
    public class Node{
        private int val;
        private int height;
        Node left;
        Node right;
        public Node(int val){
            this.val=val;
        }
        public int getVal(){
            return this.val;
        }
    }

    public int getHeight(Node node){
        if(node==null){
            return 0;
        }
        return node.height;
    }
    public void display() {
        display(this.root, "Root Node: ");
    }

    private void display(Node node, String details) {
        if (node == null) {
            return;
        }
        System.out.println(details + node.val);
        display(node.left, "Left child of " + node.val + " : ");
        display(node.right, "Right child of " + node.val + " : ");
    }
    public void populate(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            this.insert(nums[i]);
        }
    }
    public void populatedSorted(int[] nums) {
        populateSorted(nums, 0, nums.length);
    }
    private void populateSorted(int[] nums,int start,int end) {
        if(start >= end){
            return;
        }
        int mid=start + (end-start)/2;
        this.insert(nums[mid]);
        populateSorted(nums,start,mid);
        populateSorted(nums,mid+1,end);
    }
    public boolean isEmpty() {
        return root == null;
    }
    private Node root;
    public void insert(int val){
        root=insert(val,root);
    }
    private Node insert(int val,Node node){
        if(node==null){
            return new Node(val);
        }
        if(val < node.val){
            node.left=insert(val,node.left);
        }
        if(val > node.val){
            node.right=insert(val,node.right);
        }
        node.height=Math.max(getHeight(node.left),getHeight(node.right)) +1;
        return node;
    }
    public boolean balanced(){
        return balanced(root);
    }
    private boolean balanced(Node node){
        if(node==null){
            return true;
        }
        return (Math.abs(getHeight(node.left) - getHeight(node.right)) <= 1) && balanced(node.left) && balanced(node.right);
    }

    public void PreOrder(Node node){
        if(node==null){
            return;
        }
        System.out.print(node.val + " -> ");
        PreOrder(node.left);
        PreOrder(node.right);
    }

    public void InOrder(Node node){
        if(node==null){
            return;
        }
        InOrder(node.left);
        System.out.print(node.val + " -> ");
        InOrder(node.right);
    }
    public void PostOrder(Node node){
        if(node==null){
            return;
        }
        PostOrder(node.left);
        PostOrder(node.right);
        System.out.print(node.val + " -> ");
    }

    public static void main(String[] args) {
        BST tree = new BST();
        int[] nums = { 10 ,13 , 15 , 29 };
        tree.populatedSorted(nums);
        tree.display();
        tree.PostOrder(tree.root);
        System.out.println("END");
        tree.PreOrder(tree.root);
        System.out.println("END");
        tree.InOrder(tree.root);
        System.out.println("END");
    }
}
