#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
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
  // NOTE: space - O(1), time = O(n^2)
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
  // NOTE: space - O(1), time = O(n^2)
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
void insertionSort(std::vector<int> &arr) {
  // NOTE: space - O(1), time = O(n^2)
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j] < arr[j - 1])
        swap(arr, j, j - 1);
      else
        break;
    }
  }
}

std::vector<int> merge(std::vector<int> &arr1, std::vector<int> &arr2) {
  std::vector<int> combine;
  int i = 0, j = 0, m = arr1.size(), n = arr2.size();
  while (i < m && j < n) {
    if (arr1[i] < arr2[j])
      combine.emplace_back(arr1[i++]);
    else
      combine.emplace_back(arr2[j++]);
  }
  while (i < m)
    combine.emplace_back(arr1[i++]);
  while (j < n)
    combine.emplace_back(arr2[j++]);
  return combine;
}
void mergeSort(std::vector<int> &arr, int left, int right) {
  // NOTE: space - O(n), time = O(n.log(n))
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;

  std::vector<int> firstHalf(arr.begin() + left, arr.begin() + mid + 1);
  std::vector<int> secondHalf(arr.begin() + mid + 1, arr.begin() + right + 1);
  mergeSort(firstHalf, 0, firstHalf.size() - 1);
  mergeSort(secondHalf, 0, secondHalf.size() - 1);
  arr = merge(firstHalf, secondHalf);
}

void quickSort(std::vector<int> &arr, int low, int high) {
  // NOTE: space - O(1), time = O(n.log(n))
  if (low >= high)
    return;
  int i = low, j = high;
  int m = i + (j - i) / 2;
  int mid = arr[m];
  while (i <= j) {
    while (arr[i] < mid)
      i++;
    while (arr[j] > mid)
      j--;
    if (i <= j) {
      swap(arr, i, j);
      i++;
      j--;
    }
  }
  quickSort(arr, low, j);
  quickSort(arr, i, high);
}
void countingSort(std::vector<int> &arr) {
  // NOTE: this is only for positive nums for neg take min and max and shift it
  // space - O(k), O(n + k), where n = number of elements, k is the max element
  if (arr.size() == 0)
    return;
  int max = *std::max_element(arr.begin(), arr.end());
  std::vector<int> freq(max + 1, 0);

  for (int num : arr)
    freq[num]++;

  for (int i = 0, j = 0; i <= max; i++) {
    while (freq[i]-- > 0)
      arr[j++] = i;
  }
}

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
