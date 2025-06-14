class bs2D {
  public static void main(String[] args) {
    int[][] matrix1 = {
        { -100, -50, -10, -5 },
        { -4, -1, 0, 3 },
        { 5, 8, 15, 20 },
        { 25, 30, 50, 100 }
    };
    int target1 = 15;

    int[][] matrix2 = {
        { 1, 10, 20, 30 },
        { 40, 50, 60, 70 },
        { 80, 90, 100, 110 },
        { 120, 130, 140, 150 }
    };
    int target2 = 90;

    assert (searchMatrix(matrix1, target1) == true);
    assert (searchMatrix(matrix2, target2) == true);
    assert (search(matrix2, target2) == true);
    assert (search(matrix2, target2) == true);
    assert (search(matrix1, 100) == true);
    // just for learning run with -ea flag i.e - java - ea bs2D.java
    assert (searchMatrix(matrix2, 44)) : "44 should be absent";

    System.out.println("Found target1: " + searchMatrix(matrix1, target1));
    System.out.println("Found target2: " + searchMatrix(matrix2, target2));
  }

  // NOTE: Time - O(log(m) + log(n))
  public static boolean searchMatrix(int[][] matrix, int target) {
    int m = matrix.length, n = matrix[0].length;
    int sr = 0, lr = m - 1, tarRow = 0;
    while (sr <= lr) {
      tarRow = sr + (lr - sr) / 2;
      if (matrix[tarRow][0] <= target && matrix[tarRow][n - 1] >= target)
        break;
      else if (matrix[tarRow][0] > target)
        lr = tarRow - 1; // IMPORTANT: as we have checked whole tarRow Think i.e why we can do -1
      else
        sr = tarRow + 1;
    }

    int i = 0, j = n - 1;
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (matrix[tarRow][mid] == target) {
        // System.out.println(tarRow + " " + mid);
        return true;
      } else if (matrix[tarRow][mid] > target)
        j = mid - 1;
      else
        i = mid + 1;
    }

    return false;
  }

  // NOTE: Time - O(m+n)
  public static boolean search(int[][] matrix, int target) {
    int m = matrix.length, n = matrix[0].length;
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] > target)
        col--;
      else
        row++;
    }
    return false;
  }
}
