package Trees;

public class Segment {
    class Node{
        int data;
        int startInterval;
        int endInterval;
        Node left;
        Node right;
        Node(int startInterval,int endInterval){
            this.startInterval=startInterval;
            this.endInterval=endInterval;
        }
    }
    Node root;
    public Segment(int[] arr){
        this.root = this.construct(arr,0, arr.length-1);
    }
    private Node construct(int[] arr,int start,int end) {
        if(start==end){
            Node leaf=new Node(start,end);
            leaf.data=arr[start];
            return leaf;
        }
        Node node=new Node(start,end);
        int mid=start+ (end-start)/2;

        node.left=this.construct(arr,start,mid);
        node.right=this.construct(arr,mid+1,end);

        node.data= node.left.data + node.right.data;       // adding inorder to perform the Query
        return node;
    }

    public int query(int qsi,int qei){   // query start index , query end index
        return query(this.root,qsi,qei);
    }
    private int query(Node node, int qsi, int qei) {
        if (node.startInterval >= qsi && node.endInterval <= qei) {
            // node is in the interval
            return node.data;
        } else if (node.endInterval < qsi || node.startInterval > qei) {
            // completely outside
            return 0;
        } else {
            return this.query(node.left, qsi, qei) + this.query(node.right, qsi, qei);
        }
    }


    public void update(int index,int value){
        this.root.data= update(root,index,value);
    }
    public int update(Node node,int index,int value){
        if(index >= node.startInterval && index <= node.endInterval){
            if(index== node.startInterval && index== node.endInterval){
                return node.data;
            }
            else {
                int leftans=update(node.left , index,value);
                int rightans=update(node.right , index,value);
                node.data=leftans+rightans;
                return node.data;
            }
        }
        return node.data;
    }
    public void display(){
        display(root);
    }

    private void display(Node node) {
        String str = "";

        if(node.left != null) {
            str = str + "Interval=[" + node.left.startInterval + "-" + node.left.endInterval + "] and data: " + node.left.data + " => ";
        } else {
            str = str + "No left child";
        }

        // for current node
        str = str + "Interval=[" + node.startInterval + "-" + node.endInterval + "] and data: " + node.data + " <= ";

        if(node.right != null) {
            str = str + "Interval=[" + node.right.startInterval + "-" + node.right.endInterval + "] and data: " + node.right.data;
        } else {
            str = str + "No right child";
        }

        System.out.println(str + '\n');

        // call recursion
        if(node.left != null) {
            display(node.left);
        }

        if(node.right != null) {
            display(node.right);
        }
    }
    public static void main(String[] args) {
        int[] arr = {3, 8, 6, 7, -2, -8, 4, 9};
        Segment tree = new Segment(arr);
         tree.display();

        System.out.println(tree.query(1, 6));
    }
}
