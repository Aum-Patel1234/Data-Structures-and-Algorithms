package Array;

public class kadane_algo {
    public static void main(String[] args) {
        int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
        // The subarray [4,-1,2,1] has the largest sum 6.
        System.out.println("Maximum SubArray sum is - "+maxSubArray(arr));
    }

    public static int maxSubArray(int[] nums) {
        int current_sum = 0,max_sum = Integer.MIN_VALUE;

        for(int num:nums){
            current_sum += num;
            max_sum = Math.max(max_sum,current_sum);

            if(current_sum < 0){
                current_sum = 0;
            }
        }

        return max_sum;
    }
}
