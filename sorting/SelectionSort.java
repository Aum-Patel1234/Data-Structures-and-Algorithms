package sorting;

import java.util.Arrays;

import static sorting.BubbleSort.swap;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr={9,8,7,65,3,2,1};
        Selection(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void Selection(int[] arr){
        for (int i = arr.length-1; i >= 0 ; i--) {
            swap(arr,maxindex(arr,i),i);
        }
    }
    public static int maxindex(int[] arr, int last)
    {
        int max=0;
        for (int i = 0; i <= last ; i++) {
            if(arr[i] > arr[max])
            {
                max=i;
            }
        }
        return max;
    }
}

