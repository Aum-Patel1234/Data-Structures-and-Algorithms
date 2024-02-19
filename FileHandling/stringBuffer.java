package FileHandling;

import java.util.Random;

public class stringBuffer {
    public static void main(String[] args) {
        StringBuffer sb=new StringBuffer(20);
        System.out.println(sb.capacity());

        System.out.println(sb.getClass());
        System.out.println();
        RandomString(sb.capacity());

        // StringBuffer Functions
        sb.append("Aum Patel");
        System.out.println(sb);
//        sb.replace(3, 3, ",");
//        System.out.println(sb);
        sb.insert(3," Jayraj" );
        System.out.println(sb);
        //                          USE .length() function more instead of capacity.
        sb=reverse(sb);
        System.out.println(sb);
        sb.reverse();
        System.out.println(sb);
    }
    static StringBuffer reverse(StringBuffer sb){
        StringBuffer s = new StringBuffer(sb.length());


        for (int i = 0; i < sb.length(); i++) {
            s.append(sb.charAt(sb.length() - 1 - i));
        }

        return s;
    }

    private static void RandomString(int size){
        StringBuffer sb=new StringBuffer(size);
        int a=65;
        Random r=new Random();
        for (int i = 0; i < 26 ; i++) {
            sb.append((char)(a+r.nextFloat()*26));
        }
        System.out.println(sb);
    }
}
