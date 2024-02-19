package StackQueue;

public class CircularQueue {
    protected int[] data;
    static int rear;
    static int front;
    private static final int DEFAULT_SIZE = 10;
    public CircularQueue() {
        this(DEFAULT_SIZE);
    }
    public CircularQueue(int size) {
        this.data = new int[size];
        rear = 0;
        front = 0;
    }

    public boolean isFull() {
        return (rear + 1) % data.length == front % data.length;
    }

    public boolean isEmpty() {
        return rear == front;
    }

    public void push(int val) throws Exception {
        if (isFull() ) {
            throw new Exception("Queue is Full, can't insert!");
        }
        data[rear] = val;
        rear = (rear + 1) % data.length;
    }

    public int pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is Empty, can't Pop!");
        }
        int val = data[front];
        front = (front + 1) % data.length;
        return val;
    }

    public void display() {
        for (int i = front; i != rear; i = (i + 1) % data.length) {
            System.out.print(data[i] + " ");
        }

        System.out.println("END");
    }

    public static void main(String[] args) throws Exception {
        CircularQueue cqueue = new CircularQueue(5);
        cqueue.push(12);
        cqueue.push(13);
        cqueue.push(14);
        cqueue.push(15);
//        cqueue.push(16);         not accepting the 5th one because 4+1 % 5=0

        cqueue.display();
        System.out.println(cqueue.pop());
        System.out.println(cqueue.pop());
//        System.out.println(cqueue.pop());
//        System.out.println(cqueue.pop());
        cqueue.push(122);
        cqueue.display();
    }
}
