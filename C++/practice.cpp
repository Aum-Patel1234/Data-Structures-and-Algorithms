#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {11, 43, 22, 67, 35};
  std::sort(vec.begin(), vec.end());

  int min = 0, max = 0;
  int i = 0, j = vec.size() - 1; // for min
  int s = 0, e = vec.size() - 1; // for max
  int extrabooks = 2;

  while (i < j) {
    min += vec[i];
    max += vec[e];

    j -= extrabooks;
    s += extrabooks;

    i++;
    e--;
  }

  std::cout << "min = " << min << std::endl;
  std::cout << "max = " << max << std::endl;

  return 0;
}
