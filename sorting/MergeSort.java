package sorting;
import java.util.Arrays;

import static sorting.BubbleSort.swap;
public class MergeSort {
    public static void main(String[] args) {
        int[] arr={5,4,3,2,1};
        arr=Merge(arr);
        System.out.println(Arrays.toString(arr));
    }
    static int[] Merge(int[] arr){
        if(arr.length==1)
        {
            return arr;
        }

        int m= arr.length/2;

        int[] left=Merge(Arrays.copyOfRange(arr, 0, m));
        int[] right=Merge(Arrays.copyOfRange(arr,m,arr.length));

        return MergedArr(left,right);
    }
    static int[] MergedArr(int[] left,int[] right)
    {
        int[] ans=new int[left.length+ right.length];
        int i=0;
        int j=0;
        int k=0;

        while(i!= left.length && j!= right.length)
        {
            if(left[i] > right[j])
            {
                ans[k]=right[j];
                j++;
            }
            else {
                ans[k]=left[i];
                i++;
            }
            k++;
        }

        while (i!= left.length){
            ans[k]=left[i];
            i++;
            k++;
        }
        while (j!= right.length){
            ans[k]=right[j];
            j++;
            k++;
        }
        return ans;
    }
}
