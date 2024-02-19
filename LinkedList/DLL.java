package LinkedList;

public class DLL {
    private Node head;
    private Node tail;
    private int size;
    DLL(){
        this.size=0;
    }
    private class Node{
        private int val;
        private Node next;
        private Node prev;
        Node(int val){
            this.val=val;
        }
        Node(int val, Node next, Node prev){
            this.val=val;
            this.next = next;
            this.prev = prev;
        }
    }
    public void InsertFirst(int val){
        Node node = new Node(val);
        node.next=head;
        node.prev=null;
        if (head!=null){
            head.prev=node;
        }
        if(tail==null){
            tail=node;
        }
        head=node;
        size++;
    }
    public void displayDLL(){
        Node temp=head;
        while (temp != null){
            System.out.print(temp.val + " <-> ");
            temp=temp.next;
        }
        System.out.print("END");
        System.out.println();
    }
    public void displayDLLReverse(){
        Node temp=head;
        while (temp.next != null) {
            temp = temp.next;              // Now the temp node is pointing to the last node and then we go
        }                                   // print while going backwards
        while (temp != null){
            System.out.print(temp.val + " <-> ");    // can also use tail
            temp =temp.prev;
        }
        System.out.print("END");
        System.out.println();
    }
    public void insertAtLast(int val){
        if(head==null){
            System.out.println("DLL is not created create one first.");
            return;
        }
        Node node=new Node(val);
        node.prev=tail;
        tail.next=node;
        node.next=null;
        tail=node;
        size++;
    }
    public void insertAtaPosition(int val,int index){
        if(head==null){
            System.out.println("DLL is not created create one first.");
            return;
        }
        if(index==0){
            InsertFirst(val);
            return;
        }
        if(size==index){
            insertAtLast(val);
            return;
        }
        Node temp=head;
        Node node= new Node(val);
        for (int i = 1; i < index ; i++) {
            temp=temp.next;
        }
        node.prev=temp;
        temp.next.prev=node;
        node.next=temp.next;
        temp.next=node;
        size++;
    }
    public void deleteFirst(){
        if(head==null){
            System.out.println("DLL is not created create one first.");
            return;
        }
        head =head.next;
        head.prev=null;
        size--;
    }
    public void deleteAtLast(){
        if(head==null){
            System.out.println("DLL is not created create one first.");
            return;
        }
        tail.prev.next=null;
        tail=tail.prev;
        size--;
    }
    public void deleteAtaPosition(int index){
        if(size==0||head==null){
            System.out.println("Deletion not possible as list is not created, create one first");
        }
        if(index==1){
            deleteFirst();
            return;
        }
        if(index==size){
            deleteAtLast();
            return;
        }
        Node temp=head;
        for (int i = 1; i <index ; i++) {
            temp=temp.next;
        }
        temp.next.prev=temp.prev;
        temp.prev.next=temp.next;
        size--;
//        temp.next=null;
//        temp.prev=null;
    }
    public static void main(String[] args) {
        DLL list=new DLL();
        list.InsertFirst(23);
        list.InsertFirst(22);
        list.InsertFirst(24);
        list.InsertFirst(12);
        list.displayDLL();
        list.insertAtLast(34);
//        System.out.println(list.head.next.next.prev.next.next.val);
        list.insertAtaPosition(78,2);
        System.out.println(list.head.next.next.prev.val);
        System.out.println(list.head.next.next.next.val);
        list.deleteFirst();
        list.displayDLL();
        list.deleteAtLast();
        list.displayDLL();
//        System.out.println(list.tail.val);
        list.deleteAtaPosition(4);
        list.displayDLL();
    }
}
