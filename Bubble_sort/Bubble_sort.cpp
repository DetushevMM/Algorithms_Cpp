#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  if (n <= 0) {
    std::cout << "Не корректный размер массива\n";
    return 1;
  }

  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << '\n';
  }

  delete[] arr;
  return 0;
}