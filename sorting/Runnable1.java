package sorting;
class Gun implements Runnable {
    public void run(){
        for (int i = 0; i <100 ; i++) {
            System.out.println("hi i am Gun 1");
        }
    }
}
class Gun2 implements Runnable {
    public void run(){
        for (int i = 0; i <100 ; i++) {
            System.out.println("hi i am Gun   2");
        }
    }
}
public class Runnable1 {
    public static void main(String[] args) {
        Gun a=new Gun();
        Thread t1=new Thread(a);

        Gun2 b=new Gun2();
        Thread t2=new Thread(b);

        t1.start();
        t2.start();
    }
}
