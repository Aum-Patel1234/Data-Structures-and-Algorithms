#include <functional>
#include <iostream>
#include <string>
#include <vector>

void swap(std::vector<int> &arr, int i, int j) {
  if (i == j)
    return; // avoid self-swap issue
  arr[i] ^= arr[j];
  arr[j] ^= arr[i];
  arr[i] ^= arr[j];
}

void bubbleSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j + 1, j);
        flag = false;
      }
    }
    if (flag)
      break;
  }
}
void selectionSort(std::vector<int> &arr) {
  int n = arr.size(), min = 0;
  for (int i = 0; i < n; i++) {
    int minVal = arr[i];
    for (int j = i + 1; j < n; j++) {
      if (minVal > arr[j]) {
        minVal = arr[j];
        min = j;
      }
    }
    if (arr[i] > minVal)
      swap(arr, i, min);
  }
}
void insertionSort(std::vector<int> &arr) {}
void mergeSort(std::vector<int> &arr, int left, int right) {}
void quickSort(std::vector<int> &arr, int low, int high) {}
void countingSort(std::vector<int> &arr) {}

// helper that compares vectors
static bool equalVec(const std::vector<int> &a, const std::vector<int> &b) {
  return a == b;
}

int main() {
  using SortFn = std::function<void(std::vector<int> &)>;

  // test cases
  std::vector<std::vector<int>> cases = {
      {},                            // empty
      {1},                           // single
      {2, 1, 3},                     // small
      {5, 3, 3, 2, 1, 4},            // duplicates
      {9, 8, 7, 6, 5, 4, 3, 2, 1, 0} // reverse
  };

  // wrappers for functions with different signatures
  SortFn bubble = [](std::vector<int> &v) { bubbleSort(v); };
  SortFn selection = [](std::vector<int> &v) { selectionSort(v); };
  SortFn insertion = [](std::vector<int> &v) { insertionSort(v); };
  SortFn merge = [](std::vector<int> &v) {
    if (!v.empty())
      mergeSort(v, 0, (int)v.size() - 1);
  };
  SortFn quick = [](std::vector<int> &v) {
    if (!v.empty())
      quickSort(v, 0, (int)v.size() - 1);
  };
  SortFn counting = [](std::vector<int> &v) { countingSort(v); };

  std::vector<std::pair<std::string, SortFn>> algs = {
      {"Bubble Sort", bubble},       {"Selection Sort", selection},
      {"Insertion Sort", insertion}, {"Merge Sort", merge},
      {"Quick Sort", quick},         {"Counting Sort", counting}};

  for (auto &p : algs) {
    const std::string &name = p.first;
    SortFn fn = p.second;
    bool all_ok = true;
    for (auto tc : cases) {
      std::vector<int> expected = tc;
      std::sort(expected.begin(), expected.end());
      fn(tc); // sort in-place

      if (!equalVec(tc, expected)) {
        all_ok = false;
        break;
      }
    }
    std::cout << name << " : " << (all_ok ? "PASS" : "FAIL") << "\n";
  }

  return 0;
}
