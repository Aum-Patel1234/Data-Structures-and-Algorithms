package Recursion;

import java.util.ArrayList;

public class Recursion {
    public static void main(String[] args) {
//        Subset("","abc");
//        System.out.println(subset("","abc"));
        ArrayList<ArrayList<Integer>> ans= subsetret(new int[]{1,2,3});
        for(ArrayList<Integer> list: ans){
            System.out.println(list);
        }
    }
    static void Subset(String p,String up){
        if(up.isEmpty()){
            System.out.println(p);
            return;
        }
        char ch=up.charAt(0);

        Subset(p+ch,up.substring(1));
        Subset(p,up.substring(1));
    }
    static ArrayList<String> subset(String p,String up){
        if(up.isEmpty()){
            ArrayList<String> ans= new ArrayList<String>();
            ans.add(p);
            return ans;
        }
        char ch= up.charAt(0);

        ArrayList<String> left=subset(p+ch,up.substring(1));
        ArrayList<String> right=subset(p,up.substring(1));
        left.addAll(right);
        return left;
    }
    static ArrayList<ArrayList<Integer>> subsetret(int[] arr){
        ArrayList<ArrayList<Integer>> outer=new ArrayList<ArrayList<Integer>>();
        outer.add(new ArrayList<Integer>());
        for (int k : arr) {
            int n=outer.size();
            System.out.println(n);
            for (int i = 0; i < n; i++) {
                ArrayList<Integer> internal = new ArrayList<>(outer.get(i));
                internal.add(k);
                outer.add(internal);
            }
        }

        return outer;
    }
}
