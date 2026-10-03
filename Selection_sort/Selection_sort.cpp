#include "iostream"

int main() {
  int n = 0;
  std::cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::cout << '\n';
  
  for (int i = 0; i < n; ++i) {
    int minimum = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minimum]) {
        minimum = j;
      }
    }

    if (minimum != i) {
      int temp = arr[i];
      arr[i] = arr[minimum];
      arr[minimum] = temp;
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << '\n';
  }
  delete[] arr;
  return 0;
}