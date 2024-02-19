package StackQueue;

public class DynamicQueue extends CircularQueue{
    public DynamicQueue(){
        super();
    }
    public DynamicQueue(int size){
        super(size);
    }

    @Override
    public void push(int val) throws Exception{
        if(isFull()){
            int[] temp=new int[data.length * 2];  // temp is a local variable

            for (int i = 0 ; i < data.length ; i++) {           // increasing the size of array as needed
                temp[i]=data[(front+i)% data.length];
            }
            front=0;
            rear=data.length;
            data=temp;
        }

        super.push(val);
    }
    public static void main(String[] args) throws Exception {
        CircularQueue circularQueue=new DynamicQueue(2);
        circularQueue.push(24);
        circularQueue.push(28);
        circularQueue.push(40);
        circularQueue.push(44);
        circularQueue.push(44);

        System.out.println(circularQueue.pop());
        System.out.println(circularQueue.pop());
        System.out.println(circularQueue.pop());
        System.out.println(circularQueue.pop());

        System.out.println();
        System.out.println(circularQueue.data.length);
    }
}
