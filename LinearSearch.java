package LinearSearch;
public class LinearSearch {
    public static void main(String[] args) {
        int[] arr={3,4,52,24,4};
        int target=3;
        for (int i = 0; i < arr.length ; i++) {
            if(arr[i]== target)
            {
                System.out.println(i);
                break;
            }
        }
    }
}
