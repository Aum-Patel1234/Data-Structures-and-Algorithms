package Recursion;

import java.util.ArrayList;

public class stringsubset {
    public static void main(String[] args) {
        Permutations("","abc");
    }
    static void Permutations(String p,String up){
        if(up.isEmpty()){
            System.out.println(p);
            return;
        }

        char ch=up.charAt(0);

        for (int i = 0; i <= p.length() ; i++) {
            String f=p.substring(0,i);
            String s=p.substring(i,p.length());  //her p.length is not necessary because it will go to length-1
            Permutations(f+ch+s,up.substring(1));
        }
    }
    static ArrayList<String> Permutations1(String p, String up){
        if(up.isEmpty()){
            ArrayList<String> ans=new ArrayList<String>();
            ans.add(p);
            return ans;
        }

        ArrayList<String> ans=new ArrayList<String>();
        char ch=up.charAt(0);

        for (int i = 0; i <= p.length() ; i++) {
            String f=p.substring(0,i);
            String s=p.substring(i,p.length());  //her p.length is not necessary because it will go to length-1
            ans.addAll(Permutations1(f+ch+s,up.substring(1)));
        }

        return ans;
    }

}
