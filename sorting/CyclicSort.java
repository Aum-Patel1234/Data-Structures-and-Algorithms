package sorting;
import java.util.Arrays;

import static sorting.BubbleSort.swap;
public class CyclicSort {
    public static void main(String[] args) {
        int[] arr={5,4,3,2,1};
        cyclicsort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void cyclicsort(int[] arr){
        for (int i = 0; i < arr.length ; i++) {
            if (arr[i] != i+1)
            {
                swap(arr,arr[i]-1,i);
            }
        }
    }
//    static void sort(int[] arr) {
//        int i = 0;
//        while (i < arr.length) {
//            int correct = arr[i] - 1;
//            if (arr[i] != arr[correct]) {
//                swap(arr, i , correct);
//            } else {
//                i++;
//            }
//        }
//    }
}
