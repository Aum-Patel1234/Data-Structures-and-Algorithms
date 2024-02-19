package Trees;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Practise {
    private class Node{
        private int val;
        private int height;
        private Node left;
        private Node right;
        Node(int val){
            this.val=val;
        }
        int getVal(){
            return this.val;
        }
    }
    int getHeight(Node node){
        if(node ==null){
            return -1;
        }
        return node.height;
    }
    private Node root;
//
//    public void insert(int val){
//        this.root=insert(val,root);
//    }
//    private Node insert(int val,Node node){
//        if(node==null){
//            return new Node(val);
//        }
//        if(val < node.val){
//            node.left = insert(val,node.left);
//        }
//        if(val > node.val){
//            node.right= insert(val, node.right);
//        }
//        node.height= Math.max(getHeight(node.left) , getHeight(node.right)) +1;
//        return balance(node);
//    }
//    public void display(){
//        display(root,getHeight(root));
//    }
//    private void display(Node node,int i){
//        if(node==null){
//            return;
//        }
//        for (int j = 0; j <= i ; j++) {
//            System.out.print("\t\t");
//        }
//        System.out.println(node.val);
//        display(node.left,i-1);
//        display(node.right,i-1);
//    }
//    public boolean balanced(){
//        return Balanced(this.root);
//    }
//    private boolean Balanced(Node node){
//        if (node==null){
//            return true;
//        }
//        return (Math.abs(getHeight(node.left) - getHeight(node.right)) <= 1) && Balanced(node.left) && Balanced(node.right);
//    }
//
//    private Node balance(Node node){
//        if( !Balanced(node)){
//            if(getHeight(node.left) - getHeight(node.right) > 1) {
//                // Left heavy
//                if (!Balanced(node.left)) {
//                    return rightRotate(node);
//                }
////                if(getHeight(node.left.left) -getHeight(node.left.right) > 0){
////                    return rightRotate(node);
////              }
//                else {
//                    node.left=leftRotate(node.left);
//                    return rightRotate(node);
//                }
//            }
//            else {
//                if(getHeight(node.right.left) - getHeight(node.right.right)  > 0){
//                    node.right=rightRotate(node.right);
//                    return leftRotate(node);
//                }
//                else {
//                    return leftRotate(node);
//                }
//            }
//        }
//
//        return node;
//    }
//
//    private Node rightRotate(Node p) {
//        Node c=p.left;
//        Node t=c.right;
//
//        c.right=p;
//        p.left=t;
//        c.height= Math.max(getHeight(c.left),getHeight(c.right) + 1);
//        p.height=Math.max(getHeight(p.left),getHeight(p.right) + 1);
//        return c;
//    }
//
//    private Node leftRotate(Node p) {
//        Node c=p.right;
//        Node t=c.left;
//
//        c.left=p;
//        p.right=t;
//
//        c.height= Math.max(getHeight(c.left),getHeight(c.right) + 1);
//        p.height=Math.max(getHeight(p.left),getHeight(p.right) + 1);
//        return c;
//    }

    public List<List<Integer>> levelOrder(Node root){             // BFS TRAVERSAL
        List<List<Integer>> ans=new ArrayList<>();
        if(root==null){
            return ans;
        }

        Queue<Node> queue=new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()){
            int size= queue.size();
            List<Integer> level= new ArrayList<>();
            for (int i = 0; i < size ; i++) {
                Node current= queue.poll();
                level.add(current.val);
                if(current.left!= null){
                    queue.add(current.left);
                }
                if(current.right!= null){
                    queue.add(current.right);
                }
            }
            ans.add(level);
        }
        return ans;
    }

    public Node findSuccessor(Node root, int key){
        if (root == null) {
            return null;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            Node currentNode = queue.poll();
            if (currentNode.left != null) {
                queue.offer(currentNode.left);
            }
            if (currentNode.right != null) {
                queue.offer(currentNode.right);
            }
            if (currentNode.val == key) {
                break;
            }
        }
        return queue.peek();
    }
//    class Solution {
//        public boolean isSymmetric(TreeNode root) {
//            if(root==null)  return true;
//            return tree(root.left,root.right);
//        }
//        public boolean tree(TreeNode left,TreeNode right){
//            if(left==null || right==null){
//                if(left==right) return true;
//                else return false;
//            }
//            if(left.val!=right.val) return false;
//
//            return tree(left.left,right.right) && tree(left.right,right.left);
//        }
//    }
    //                                                                      DFS Traversal

//    class Solution {
//        public TreeNode sortedArrayToBST(int[] nums) {
//            return ans(nums,0,nums.length-1);
//        }
//        TreeNode ans(int[] nums,int s,int e){
//            if(s > e){
//                return null;
//            }
//            int m=s+(e-s)/2;
//            TreeNode l = ans(nums,s,m-1);
//            TreeNode r = ans(nums,m+1,e);
//            TreeNode node= new TreeNode(nums[m],l,r);
//            return node;
//        }
//
//    }

}
