package Maths;

public class SieveOfEratosthenes {
    public static void main(String[] args) {
        int n = 10;
        System.out.println("No of Primes within range 0 - " + n + " = " + numberOfPrimes(n));
    }

    private static int numberOfPrimes(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n is a negative number.");
        }
        int count = 0;
        boolean[] primes = new boolean[n+1]; // false means prime and true mean no prime

        for (int i = 2; i < Math.sqrt(n); i++) {
            if(!primes[i]){
                for(int j = i*i; j < n; j += i){
                    primes[j] = true;
                }
            }
        }

        for(int i = 2; i < n;i++){
            if(!primes[i]){
                count++;
            }
        }

        return count;
    }
}