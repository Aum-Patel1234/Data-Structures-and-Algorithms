import java.util.Arrays;

public class rotate{
  public static void main(String[] args) {
    int[] arr = {1,2,3,4,5};
    int[] arr1 = {10, 20, 30, 40, 50};
    int[] arr2 = {7, 8, 9, 10, 11};
    int[] arr3 = {5, 15, 25, 35, 45, 55};
    int[] arr4 = {3, 6, 9, 12, 15, 18, 21};
    rightRotate(arr, 2);
    rightRotate(arr1, 0);
    rightRotate(arr2, 1);
    rightRotate(arr3, 6);
    rightRotate(arr4, 10);
    System.out.println(Arrays.toString(arr));
    System.out.println(Arrays.toString(arr1));
    System.out.println(Arrays.toString(arr2));
    System.out.println(Arrays.toString(arr3));
    System.out.println(Arrays.toString(arr4));
  } 
  private static void rightRotate(int[] arr, int k){
    k %= arr.length;
    rotate(arr, 0, arr.length - 1);
    rotate(arr, 0, arr.length - k - 1);
    rotate(arr, arr.length - k, arr.length - 1);
  }
  private static void rotate(int[] arr, int i, int j){
    while(i < j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
}
