package sorting;

public class pat {
    public static void main(String[] args) {
        int v=1;
        int n=8;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if(i ==0 || j== 0 || i==n-1 || j==n-1 ){
                    System.out.print("4 ");
                }
                if(i>0 && i<=n-2 && j>0 &&j<=n-2){
                    System.out.print(v++ + " ");
                }
            }
            System.out.println();
        }
    }
}

