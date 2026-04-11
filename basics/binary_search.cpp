#include <cassert>
#include <iostream>
#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    // TODO:
  }
};

int main() {
  Solution s;

  std::vector<std::vector<std::vector<int>>> matrices = {
      {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}},
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      {{-5}},                                // single element
      {{1, 3, 5, 7}},                        // single row
      {{1}, {3}, {5}, {7}},                  // single column
      {},                                    // empty matrix
      {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},     // duplicates
      {{-10, -5, 0}, {1, 3, 5}, {7, 9, 11}}  // negatives + positives
  };

  std::vector<int> targets = {5, 20, -5, 7, 3, 1, 1, 9};

  std::vector<bool> expected = {true,  false, true, true, true,
                                false,  // empty matrix
                                true,  true};

  for (int i = 0; i < matrices.size(); i++) {
    bool found = s.searchMatrix(matrices[i], targets[i]);
    assert(found == expected[i]);
  }

  std::cout << "\033[32mAll test cases passed!\033[0m\n";
  return 0;
}
