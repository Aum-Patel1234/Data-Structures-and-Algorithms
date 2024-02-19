public class BinarySearch {
    public static void main(String[] args) {
        int[] arr={1,3,34,67,89};
        System.out.println(bs(arr,67));
    }
    static int bs(int[] arr,int target)
    {
        int s=0;
        int e= arr.length-1;

        while(s<=e)
        {
            int m= s+(e-s)/2;

            if(arr[m] == target)
            {
                return m;
            } else if (arr[m] > target) {
                e=m-1;
            }else {
                s=m+1;
            }
        }
        return -1;
    }
}
