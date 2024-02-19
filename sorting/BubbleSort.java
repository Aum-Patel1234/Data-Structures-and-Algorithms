package sorting;

import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr={3,1,5,45,4};
        bubblesort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void bubblesort(int[] arr){
        for (int i = 0; i <arr.length ; i++) {
            boolean j=false;
            for (int k = 0; k <arr.length-i-1 ; k++) {
                if(arr[k] > arr[k+1])
                {
                    swap(arr,k,k+1);
                    j=true;
                }
            }
            if(!j)
            {
                return;
            }
        }
    }
    public static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}

