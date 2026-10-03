#include <iostream>

bool ComparatorInt(int x, int y) {
  return x < y;
}

int* MergeArrays(const int* arr1, int n, const int* arr2, int m, bool (*comp)(int, int)) {
  int* result = new int[n + m];
  
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n && j < m) {
    if (comp(arr1[i], arr2[j])) {
      result[k++] = arr1[i++];
    } else {
      result[k++] = arr2[j++];
    }
  }

  while (i < n) {
    result[k++] = arr1[i++];
  }

  while (j < m) {
    result[k++] = arr2[j++];
  }

  return result;
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr1 = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr1[i];
  }

  int m = 0;
  std::cin >> m;
  int* arr2 = new int[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> arr2[i];
  }
  
  int* merged = MergeArrays(arr1, n, arr2, m, ComparatorInt);

  for (int i = 0; i < n + m; ++i) {
    std::cout << '\n' << merged[i] << '\n';
  }

  delete[] arr1;
  delete[] arr2;
  delete[] merged;

  return 0;
}