package String_algorithms;

public class KarpRabin {
    public static void main(String[] args) throws Exception {
        KarpRabinAlgo algorithm = new KarpRabinAlgo();
        System.out.println(algorithm.search("abababcabcd", "abcd"));
    }
}

class KarpRabinAlgo{
    private final int PRIME = 37;

    private double gethashofString(String str){
        double hash = 0;
        for (int i = 0; i < str.length() ; i++) {
            hash += str.charAt(i)*Math.pow(PRIME,i);
        }
        return hash;
    }

    private double updatehash(double prevHash , char old , char newChar , int patternLength){
        double newHash = (prevHash - old) / PRIME;
        newHash += newChar * Math.pow(PRIME,patternLength-1);
        return newHash;
    }

    public int search(String str, String pattern){
        int patternLength = pattern.length();
        double hash = gethashofString(pattern);
        double currenthash = gethashofString(str.substring(0,patternLength));

        for(int i = 0 ; i <= str.length() - patternLength ; i++ ){
            if(hash == currenthash){
                if(str.substring(i, i + patternLength).equals(pattern)){
                    return i;
                }
            }

            if(i < str.length() - patternLength){
                currenthash = updatehash(currenthash , str.charAt(i) , str.charAt(i+patternLength) , patternLength);
            }
        }
        return -1;
    }
}