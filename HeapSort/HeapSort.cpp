#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void ShiftDown(int* array, int n, int m) {
  if (array == nullptr || n <= 0 || m < 0 || m >= n) {
    return;
  }
  int bigger = m;
  int left = 2 * m + 1;
  int right = 2 * m + 2;

  if (left < n && array[left] > array[bigger]) {
    bigger = left;
  }
  if (right < n && array[right] > array[bigger]) {
    bigger = right;
  }
  if (bigger != m) {
    Swap(array[m], array[bigger]);
    ShiftDown(array, n, bigger);
  }
}

void HeapSort(int* array, int n) {
  for (int i = n / 2 - 1; i >= 0; --i) {
    ShiftDown(array, n, i);
  }

  for (int i = n - 1; i > 0; --i) {
    Swap(array[0], array[i]);
    ShiftDown(array, i, 0);
  }
}

int main() {
  int n = 0;
  std::cin >> n;

  int* array = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
  }

  HeapSort(array, n);

  for (int i = n - 1; i >= 0; --i) {
    std::cout << array[i] << '\n';
  }

  delete[] array;
  return 0;
}