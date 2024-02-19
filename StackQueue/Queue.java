package StackQueue;

public class Queue {
    protected int[] data;
    static int rear=-1;
//    static int front=-1;
    private static final int DEFAULT_SIZE=10;
    public Queue(){
        this(DEFAULT_SIZE);
    }
    public Queue(int size){
        this.data=new int[size];
    }
    public boolean isFull(){
        return rear==data.length-1;
    }
    public boolean isEmpty(){
        return  rear==-1;
    }
    public void push(int val) throws Exception{
        if(isFull()){
            throw new Exception("Queue is Full , can't insert!");
        }
        rear++;
        data[rear]=val;
    }
    public int pop() throws Exception{
        if(isEmpty()){
            throw new Exception("Queue is Empty, can't pop!");
        }
        int removed=data[0];
        for (int i = 1; i <= rear ; i++) {
            data[i-1]=data[i];
        }
        rear--;
        return removed;
//        front++;
//        return data[front];
    }
    public void display(){
        if(isEmpty()){
            System.out.println("Queue is not created!");
            return;
        }
        for (int i = 0; i <= rear ; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println("END");
    }

    public static void main(String[] args) throws Exception{
        Queue queue = new Queue(5 );
        queue.push(12);
        queue.push(13);
        queue.push(14);
        queue.push(15);
        queue.push(16);

        queue.display();
        System.out.println(queue.pop());
        queue.display();
    }
}
