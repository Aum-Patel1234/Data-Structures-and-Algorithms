package sorting;

import java.util.Arrays;

public class DutchNationalFlagAlgo {
    public static void main(String[] args) {
        int[] colors = new int[]{2,0,2,1,1,0};          // problem 75
        sortColors(colors);
        System.out.println(Arrays.toString(colors));
    }
    // Intuition:

    // The idea is to maintain three pointers:
    // lo tracks the boundary for 0s.
    // hi tracks the boundary for 2s.
    // mid processes the current element.

    // Steps:
    // If nums[mid] == 2, swap it with nums[hi] and decrement hi (moving 2s to the right).
    // If nums[mid] == 0, swap it with nums[lo], increment both lo and mid (moving 0s to the left).
    // If nums[mid] == 1, simply move mid forward (1s are in the middle).
    // This approach sorts the array in-place in one pass, using O(n) time and O(1) space.
    public static void sortColors(int[] nums) {
        int lo = 0, mid = 0, hi = nums.length - 1;

        while (mid <= hi) {
            if (nums[mid] == 2) {
                swap(nums, mid, hi);
                hi--;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums,mid,lo);
                mid++;
                lo++;
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
