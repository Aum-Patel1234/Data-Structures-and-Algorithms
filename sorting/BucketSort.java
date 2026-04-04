import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class BucketSort {
  static void swap(List<Integer> arr, int i, int j) {
    int temp = arr.get(i);
    arr.set(i, arr.get(j));
    arr.set(j, temp);
  }

  static void insertionSort(List<Integer> arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
      int idx = i;
      while (idx > 0) {
        if (arr.get(idx) < arr.get(idx - 1))
          swap(arr, idx, idx - 1);
        idx--;
      }
    }
  }

  static void bucketSort(int[] arr) {
    int n = arr.length;

    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    for (int num : arr) {
      min = Math.min(min, num);
      max = Math.max(max, num);
    }
    int bucketLength = (int) Math.sqrt(n);
    double rangePerBucket = (max - min + 1) / bucketLength;
    // System.out.println(rangePerBucket);

    List<List<Integer>> buckets = new ArrayList<>(bucketLength);
    for (int i = 0; i < n; ++i)
      buckets.add(new ArrayList<>());

    for (int num : arr) {
      int bucketIdx = (int) ((num - min) / rangePerBucket);
      buckets.get(bucketIdx).add(num);
    }

    for (List<Integer> bucket : buckets)
      insertionSort(bucket);

    int i = 0;
    for (List<Integer> bucket : buckets) {
      for (int num : bucket)
        arr[i++] = num;
    }
  }

  public static boolean isSorted(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
      if (arr[i] < arr[i - 1])
        return false;
    }
    return true;
  }

  public static void printArray(int[] arr) {
    System.out.println(Arrays.toString(arr));
  }

  public static void main(String[] args) {
    int[] arr1 = { 5, 3, 8, 1, 2 };
    BucketSort.bucketSort(arr1);
    printArray(arr1);
    assert isSorted(arr1);

    int[] arr2 = { 1, 2, 3, 4, 5 };
    BucketSort.bucketSort(arr2);
    assert isSorted(arr2);

    int[] arr3 = { 9, 7, 5, 3, 1 };
    BucketSort.bucketSort(arr3);
    assert isSorted(arr3);

    int[] arr4 = { 4, 2, 2, 8, 3, 3, 1 };
    BucketSort.bucketSort(arr4);
    assert isSorted(arr4);

    int[] arr5 = { 10 };
    BucketSort.bucketSort(arr5);
    assert isSorted(arr5);

    System.out.println("\033[32mAll test cases passed!\033[0m");
  }
}
