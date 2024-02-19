package Recursion;
import sorting.MergeSort;

import java.util.Arrays;
import static sorting.BubbleSort.swap;
import static sorting.SelectionSort.maxindex;
public class Backtracking {
    public static void main(String[] args) {
        int[] arr={345,34,234,234,4,56,6,7,45,5,55,44};
        quick(arr,0, arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    private static void quick(int[] a, int i, int j) {
        if (i >= j) {
            return;
        }
        int low = i;
        int hi = j;
        int pivotIndex = i + (j - i) / 2;
        int pivot = a[pivotIndex]; // Fix: Use the value at pivotIndex as the pivot

        while (low <= hi) {
            while (a[low] < pivot) {
                low++;
            }
            while (a[hi] > pivot) {
                hi--;
            }

            if (low <= hi) {
                swap(a, low, hi);
                low++;
                hi--;
            }
        }
        quick(a, i, hi);
        quick(a, low, j);
    }

}
