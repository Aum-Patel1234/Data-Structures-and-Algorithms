package sorting;

public class Subsets{
    public static void main(String[] args) {
        System.out.println(isPrime(97,2));
    }
    static boolean isPrime(int a,int i){
        if( a%i==0){
            return false;
        }
        if(i*i > a){
            return true;
        }
        return isPrime(a,i+1);
    }
}