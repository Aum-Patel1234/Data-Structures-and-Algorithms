package StackQueue;

public class DynamicStack extends Stack{
    public DynamicStack(){
        super();
    }
    public DynamicStack(int size){
        super(size);
    }

    @Override
    public void push(int val) {
        if(isFull()){
            int[] temp=new int[data.length * 2];  // temp is a local variable

            for (int i = 0; i < data.length ; i++) {           // increasing the size of array as needed
                temp[i]=data[i];
            }
            data=temp;
        }

        super.push(val);
    }
    public static void main(String[] args) throws Exception {
        Stack stack=new DynamicStack(2);
        stack.push(24);
        stack.push(28);
        stack.push(40);
        stack.push(44);
        stack.push(44);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());

        System.out.println(stack.data.length);
    }
}
