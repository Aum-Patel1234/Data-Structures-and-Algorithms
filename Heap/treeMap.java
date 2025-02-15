package Heap;

public class treeMap {
    public static void main() {
      
    }  
    class Solution {
        public long findScore(int[] nums) {
            TreeMap<Integer,List<Integer>> tm = new TreeMap<>();

            for(int i = 0;i < nums.length;i++){
                int num = nums[i];
                if(tm.get(num) != null){
                    List<Integer> l = tm.get(num);
                    l.add(i);
                }else{
                    List<Integer> l = new ArrayList<>();
                    l.add(i);
                    tm.put(num,l);
                }
            }

            // System.out.println(tm);

            long score = 0;
            boolean[] marked = new boolean[nums.length];

            while(!tm.isEmpty()){
                // System.out.println(tm.pollFirstEntry());
                Map.Entry<Integer,List<Integer>> entry = tm.firstEntry();
                List<Integer> l = entry.getValue();

                int index = entry.getValue().get(0);
                if(marked[index]){
                    if(l.size() == 1){
                        tm.pollFirstEntry();
                    }else{
                        l.remove(0);
                    }
                    continue;
                }
                
                if(l.size() == 1){
                    // Map.Entry<Integer,List<Integer>> entry = tm.pollFirstEntry();
                    score += (long)(tm.pollFirstEntry().getKey());
                }else{
                    score += (long)(entry.getKey());
                    l.remove(0);                
                }

                if(index + 1 < nums.length){
                    marked[index+1] = true;
                }
                if(index - 1 >= 0){
                    marked[index-1] = true;
                }
                // System.out.println(tm+ " " + Arrays.toString(marked) + "\t\t" + index + " " + score);

            }

            return score;
        }
    }
}
