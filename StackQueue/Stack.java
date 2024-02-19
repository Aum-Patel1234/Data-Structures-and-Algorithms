package StackQueue;

public class Stack {
    protected int[] data;
    static int top=-1;
    private static final int DEFAULT_SIZE=10;
    public Stack(){
        this(DEFAULT_SIZE);
    }
    public Stack(int size){
        this.data=new int[size];
    }
    public void push(int val){
        if(isFull()){
            System.out.println("Stack is full , can't insert.");
            return;
        }
        top++;
        data[top]=val;
    }
    public int pop() throws Exception{
        if(isEmpty()){
            throw new Exception("Can't pop Stack is Empty!");
        }
        return data[top--];
    }
    public boolean isFull() {
        return top == data.length - 1;
    }
    public boolean isEmpty(){
        return top == -1;
    }
    public int peek() throws Exception{
        if(isEmpty()){
            throw new Exception("Can't pop Stack is Empty!");
        }
        return data[top];
    }

    public static void main(String[] args) throws Exception {
        Stack stack=new Stack();
        stack.push(24);
        stack.push(28);
        stack.push(40);
        stack.push(44);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());

    }
}
