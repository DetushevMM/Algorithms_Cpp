#include "iostream"

void InsertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int current = arr[i];
    int j = 0;
    for (j = i - 1; j >=0 && arr[j] > current; --j) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = current;
  }
}

int main() {
  int n = 0;
  std::cin >> n;

  int numbers[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }
  std::cout << '\n';

  InsertionSort(numbers, n);

  for (int i = 0; i < n; ++i) {
    std::cout << numbers[i] << '\n';
  }
  return 0;
}