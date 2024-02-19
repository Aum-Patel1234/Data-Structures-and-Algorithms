package Recursion;

import java.util.ArrayList;

// can only go in two directions right and down in a 2D maze
public class BTpaths {
    public static void main(String[] args) {
//        System.out.println(NumOfPaths(3,3));
//        Paths("",3,3);
        boolean[][] maze={
                {true,true,true},
                {true,true,true},
                {true,true,true}
        };
        Backtrck("",maze,0,0);
    }
    static int NumOfPaths(int r,int c){
        if( r==1 || c==1){
            return 1;
        }
        int left=NumOfPaths(r-1,c);
        int right=NumOfPaths(r,c-1);
        int d=NumOfPaths(r-1,c-1); //Diagonally
        return left+right+d;
    }
    static void Paths(String p,int r,int c){
        if(r==1 && c==1){
            System.out.println(p);
            return;
        }
        if(r>1){
            Paths(p+"V",r-1,c);
        }
        if(c>1){
            Paths(p+"H",r,c-1);
        }
        if(r>1 &&c>1){
            Paths(p+"D",r-1,c-1);
        }
    }

    static void Backtrck(String p,boolean[][] maze,int r,int c){
        if(r== maze.length-1 && c== maze[0].length-1){
            System.out.println(p);
            return;
        }
        if(!maze[r][c]){
            return;         // Thus it does not go in infinite loop
        }
        maze[r][c]=false; //-------------------------------------------------------------------- BACKTRACKING
        if(r< maze.length-1){
            Backtrck(p+"D",maze,r+1,c);
        }
        if(c< maze[0].length-1){
            Backtrck(p+"R",maze,r,c+1);
        }
        if(r>0){
            Backtrck(p+"U",maze,r-1,c);
        }
        if (c > 0) {
            Backtrck(p+"L",maze,r,c-1);
        }
        maze[r][c]=true; //--------------------------------------------------------------------- BACKTRACKING
    }
}
