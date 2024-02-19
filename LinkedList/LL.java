package LinkedList;
public class LL {
    private int size;
    private Node head;
    private Node tail;
    public LL(){
        this.size=0;
    }
    //Node is created
    class Node{
        Node next;
        private int val;
        Node(int val,Node next){
            this.val=val;
            this.next=next;
        }
        Node(int val){
            this.val=val;
        }
        Node(){}
    }
    public void insertAtaPosition(int val,int pos){
        if(head==null){
            insertFirst(val);
            return;
        }
        if (pos==0){
            insertFirst(val);
            return;
        }
        if(pos==size){
            insertAtLast(val);
            return;
        }
        Node temp=head;
        for (int i = 1; i < pos ; i++) {
            temp=temp.next;                      // node is at correct position
        }
        Node node=new Node(val,temp.next);
        temp.next=node;
        size++;
    }
    public void display(){
        Node temp=head;
        while (temp!=null){
            System.out.print(temp.val+" -> ");
            temp=temp.next;
        }
        System.out.println("END");
    }
    public void insertFirst(int val){
        Node node=new Node(val);
        node.next=head;
        head=node;
        if(tail==null){
            tail=head;
        }
        size++;
    }
    public void insertAtLast(int val){
        if(head==null){
            insertFirst(val);
            return;
        }
        Node node=new Node(val);
        node.next=tail.next;
        tail.next=node;
        tail=node;
        size++;
    }
    public int deleteFirst() {
        if (size <= 1) {
            return deleteFirst();
        }
        int val = head.val;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        size--;
        return val;
    }
    public void deleteLast(){
        if(head==null || tail==null){
            System.out.println("Linked list is not created,Please create one.");
            return;
        }
        Node temp=head;
        while (temp.next!=tail){
            temp=temp.next;
        }
        temp.next=null;
        tail=temp;
        size--;
    }
    public void deleteAtAPosition(int index){
        if(head==null || tail==null){
            System.out.println("Linked list is not created,Please create one.");
            return;
        }
        if(index==0){
            deleteLast();
            return;
        }
        if(index==size){
            deleteLast();
            return;
        }
        Node temp=head;
        for (int i = 0; i < index-1 ; i++) {
            temp=temp.next;
        }
        Node del=temp.next;
        temp.next=del.next;
        del.next=null;
        size--;
    }
    public void insertRec(int val,int index,Node temp){
        if(index < 0){
            throw new IllegalArgumentException("Invalid index");
        }
        if(index==0){
            insertFirst(val);
            return;
        }
        if(index==1){
            Node node=new Node(val);
            node.next=temp.next;
            temp.next=node;
            size++;
            return;
        }
        insertRec(val,index-1,temp.next);
    }
    public void duplicates() {
        Node node = head;

        while (node.next != null) {
            if (node.val == node.next.val) {
                node.next = node.next.next;
                size--;
            } else {
                node = node.next;
            }
        }
        tail = node;
        tail.next = null;
    }
    public Node mid(Node head){
        Node f=head;
        Node s=head;
        while (f!=null && f.next!=null){
            f=f.next.next;
            s=s.next;
        }
        return s;
    }
    public Node Merge(Node f,Node s){
        Node dhead=new Node();
        Node tail=dhead;
        while (f!=null && s!=null){
            if(f.val < s.val){
                tail.next=f;
                f=f.next;
                tail=tail.next;
            }
            else{
                tail.next=s;
                s=s.next;
                tail=tail.next;
            }
        }
        tail.next = (f!=null)?f:s;
        return dhead.next;
    }
    public Node mergesort(Node head){
        if(head==null || head.next==null){
            return head;
        }
        Node mid=mid(head);
        Node left=mergesort(head);   // E R R O R
        Node right=mergesort(mid);
        return Merge(left,right);
    }
    public void reverse(Node node){
        if(tail==node){
            head=tail;
            return;
        }
        reverse(node.next);
        tail.next=node;
        tail=tail.next;
        tail.next=null;
    }
//    public ListNode reverseList(ListNode head) {
//        ListNode prev=null;
//        ListNode p=head;
//        if( p==null || p.next==null ){
//            return p;
//        }
//        ListNode next=p.next;
//
//        while(next!=null){
//            p.next=prev;
//            prev=p;
//            p=next;
//            next=p.next;
//        }
//        p.next=prev;
//        head=p;
//        return head;
//    }
    public static void main(String[] args) {
        LL list=new LL();
        list.insertFirst(3);
        list.insertAtLast(65);
        list.insertAtLast(2);
        list.insertAtLast(27);

        LL list1=new LL();
        list1.insertAtLast(2);
        list1.insertAtLast(23);
        list1.insertAtLast(3);
        list1.display();
        System.out.println(list1.head.val);
        System.out.println(list.head.val);

//        list.mergesort(list.head);
        list.display();
        list.reverse(list.head);
        list.display();
    }
}
