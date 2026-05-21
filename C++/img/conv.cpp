#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convolution2D(const vector<vector<int>>& a, const vector<vector<int>>& b) {
  const size_t ma = a.size(), na = a[0].size();
  const size_t mb = b.size(), nb = b[0].size();
  assert(ma >= mb);
  assert(na >= nb);
  const size_t ans_m = ma - mb + 1, ans_n = na - nb + 1;
  // cout << ans_m << " " << ans_n << endl;
  vector<vector<int>> ans(ans_m, vector<int>(ans_n));

  for (size_t i = 0; i < ans_m; ++i) {
    for (size_t j = 0; j < ans_n; ++j) {
      int dot_prod = 0;
      for (size_t k = 0; k < mb; ++k) {
        for (size_t m = 0; m < nb; ++m) {
          dot_prod += (a[i + k][j + m] * b[k][m]);
        }
      }

      ans[i][j] = dot_prod;
    }
  }

  return ans;
}

int main(int argc, char* argv[]) {
  {
    vector<vector<int>> a = {{1, 2}, {3, 4}};
    vector<vector<int>> k = {{1, 1}, {1, 1}};
    vector<vector<int>> expected = {{10}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> k = {{1, 0}, {0, 1}};
    vector<vector<int>> expected = {{6, 8}, {12, 14}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> k = {{1, 1}, {1, 1}};
    vector<vector<int>> expected = {{12, 16}, {24, 28}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> k = {{1, 0}, {0, 1}};
    vector<vector<int>> expected = {{7, 9, 11}, {15, 17, 19}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<vector<int>> k = {{1, 1}, {1, 1}};
    vector<vector<int>> expected = {{4, 4}, {4, 4}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{2, 4, 6}, {1, 3, 5}, {7, 9, 11}};
    vector<vector<int>> k = {{1, -1}, {-1, 1}};
    vector<vector<int>> expected = {{0, 0}, {0, 0}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    vector<vector<int>> k = {{1, 2}, {3, 4}};
    vector<vector<int>> expected = {{0, 0}, {0, 0}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{1, 2, 1}, {0, 1, 0}, {2, 1, 2}};
    vector<vector<int>> k = {{1, 0}, {0, 1}};
    vector<vector<int>> expected = {{2, 2}, {1, 3}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> k = {{1, 2}, {3, 4}};
    vector<vector<int>> expected = {{37, 47}, {67, 77}};
    assert(convolution2D(a, k) == expected);
  }

  {
    vector<vector<int>> a = {{5, 1, 3}, {2, 4, 6}, {7, 8, 9}};
    vector<vector<int>> k = {{0, 1}, {1, 0}};
    vector<vector<int>> expected = {{3, 7}, {11, 14}};
    assert(convolution2D(a, k) == expected);
  }
}
