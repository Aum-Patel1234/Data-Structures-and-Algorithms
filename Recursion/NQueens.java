package Recursion;
public class NQueens {
    public static void main(String[] args) {
        int n=4;
        boolean[][] board=new boolean[n][n];
        Nquuens(board,0);
    }

    private static void Nquuens(boolean[][] board, int r) {
        if(r== board.length){
            Display(board);
            System.out.println();
            return;
        }

        for (int i = 0; i < board.length ; i++) {
            if(issafe(board,r,i)){
                board[r][i]=true;
                Nquuens(board,r+1);
                board[r][i]=false;
            }
        }
    }

    private static boolean issafe(boolean[][] board, int r, int c) {
        // upwards
        for (int i = 0; i <r ; i++) {
            if (board[i][c]){
                return false;
            }
        }
        for (int i = 1; i <= Math.min(r,c) ; i++) {
            if (board[r-i][c-i]){
                return false;
            }
        }
        for (int i = 1; i <= Math.min(r,board.length-c-1) ; i++) {
            if (board[r-i][c+i]){
                return false;
            }
        }
        return true;
    }

    private static void Display(boolean[][] board) {
        for (boolean[] booleans : board) {
            for (boolean aBoolean : booleans) {
                if (aBoolean) {
                    System.out.print("Q ");
                } else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
    }
}
