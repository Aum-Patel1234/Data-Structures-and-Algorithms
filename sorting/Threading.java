package sorting;
class thread extends Thread{
    thread(){
        super("Sahil");
    }
    public void run(){
//        for (int i = 0; i <50 ; i++) {
//            System.out.println("hi i am thread1");
//        }
        while (true){
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(e);;
            }
            System.out.println("good morning");
        }
    }
}
class thread2 extends Thread{
    thread2(){
        super("aum");
    }
    public void run(){

        while (true){
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(e);;
            }
            System.out.println("hi i am thread 2");
        }

    }
}

class Example implements Runnable{
    public void run(){
        System.out.println("hi i am example");
    }
}
public class Threading {
    public static void main(String[] args) {
        thread a=new thread();
        thread2 b=new thread2();
        a.start();
        b.start();
        System.out.println(" name is "+ a.getName());
        System.out.println(" name is "+ b.getName());
        System.out.println(" id is "+ a.getId());
        System.out.println(" id is "+ b.getId());
        System.out.println(" id is "+ a.getThreadGroup());

        Example e1=new Example();
        Thread eg=new Thread(e1,"Jai Parmar");
        eg.start();
        System.out.println("my name is "+eg.getName());
    }
}
