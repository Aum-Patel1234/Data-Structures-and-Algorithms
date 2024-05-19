package sorting;

import java.util.Arrays;

public class CountSort {
    public static void main(String[] args) throws Exception {
        int[] arr = { 29, 83, 471, 36, 91, 8 };
        countSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    private static void countSort(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return;
        }
        int max = arr[0];
        for (int k : arr) {
            if (max < k) {
                max = k; // find max element
            }
        }

        int[] frequency_arr = new int[max + 1];

        for (int i = 0; i < arr.length; i++) {
            frequency_arr[arr[i]]++;
        }

        for (int i = 0, j = 0; i < frequency_arr.length; i++) {
            while (frequency_arr[i] > 0) {
                arr[j++] = i;
                frequency_arr[i]--;
            }
        }
    }
}
