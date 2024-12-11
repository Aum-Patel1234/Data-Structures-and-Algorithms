package Array;

public class Sliding_Window {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, -1 };
        int k = 4;
        System.out.println("Basic Sliding Window solution - " + maxSumForWindow(arr, k));

        int[] nums = { 2, 5, 1, 7, 10 };
        k = 14;
        System.out.println("\nLongest subarray with sum <= " + k + " is - " + maxLengthOfSubarray(nums, k));
    }

    private static int maxLengthOfSubarray(int[] nums, int k) {
        // Time - O(N+N) 
        // space - O(1)

        int maxLength = 0, left = 0, right = 0, sum = 0;

        while (right < nums.length) {
            sum += nums[right];
            while (sum > k) {           // you can turn while into an if statement when they are asking for a maxlength but not when the are
                sum -= nums[left];      // asking to print the subarray as the conditions might be different so check if this is possible 
                left++;
            }
            if(sum <= k){
                maxLength = Math.max(maxLength, right-left+1);
            }
            right++;
        }

        return maxLength;
    }

    public static int maxSumForWindow(int[] arr, int k) {
        if (arr == null || arr.length < k || k <= 0) {
            throw new IllegalArgumentException("Invalid input: array is too small or k is invalid");
        }

        int left = 0;
        int right = k - 1;
        int maxSum = Integer.MIN_VALUE;
        int sum = 0;

        for (int i = left; i <= right; i++) {
            sum += arr[i];
        }
        maxSum = Math.max(maxSum, sum);

        // now move the window forward
        while (right < arr.length - 1) {
            sum -= arr[left];
            left++;
            right++;
            sum += arr[right];
            maxSum = Math.max(maxSum, sum);
        }

        return maxSum;
    }

}
