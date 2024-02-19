package sorting;
import java.util.Arrays;

import static sorting.BubbleSort.swap;
public class InsertionSort {
    public static void main(String[] args) {
        int[] arr={12,3,12,3,34,234,1};
        insertionsort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void insertionsort(int[] arr){
        for (int i = 0; i < arr.length-1 ; i++) {
            for (int j = i+1; j >0 ; j--) {
                if(arr[j] < arr[j-1])
                {
                    swap(arr,j,j-1);
                }
                else {
                    break;
                }
            }
        }
    }
}
