import java.lang.StringBuilder;

public class cantorsDiagonalArgument{
  public static void main(String[] args) {
    System.out.println(findDifferentBinaryString(new String[]{"00","01"}));  
  }
  public static String findDifferentBinaryString(String[] nums) {
    StringBuilder ans = new StringBuilder();
    for (int i = 0; i < nums.length; i++) {
       Character curr = nums[i].charAt(i);
       ans.append(curr == '0' ? '1' : '0');
    } 
    
    return ans.toString();
  }
}
