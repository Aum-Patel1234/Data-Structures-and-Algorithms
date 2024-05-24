
import java.util.*;

public class MosAlgorithm {
    public static void main(String[] args) throws Exception{
        int[] arr = {1, 3, 5, 2, 7, 6, 3, 1, 4, 8};
        int n = arr.length;

        // build a blocks array
        int sqrt = (int) Math.sqrt(n);

        int block_id = -1;

        int[] blocks = new int[sqrt + 1];

        for (int i = 0; i < n ; i++) {
            if(i%sqrt == 0){
                block_id++;
            }
            blocks[block_id] += arr[i];
        }
        System.out.println(Arrays.toString(blocks));
        System.out.println(query(blocks, arr, 2, 7, sqrt));
    }
    private static  int query(int[] blocks,int[] arr, int l , int r , int sqrt){
        int ans = 0;

        while (l % sqrt != 0 && l<r && l!=0){
            ans += arr[l++];
        }

        while (l + sqrt <= r){
            ans += blocks[l / sqrt];
            l += sqrt;
        }

        while (l <= r){
            ans += arr[l++];
        }

        return ans;
    }
    public void update(int[] blocks , int[] arr, int i, int val, int sqrt){
        int correction_value = val - arr[i];
        blocks[i/sqrt] += correction_value;
        arr[i] = val;
    }
}