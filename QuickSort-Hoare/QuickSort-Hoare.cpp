#include <iostream>
#include <memory>

void Swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

int Partition(int arr[], int size, int low, int high) {
  if (arr == nullptr || size <= 0 || low < 0 || low > high || high >= size) {
    return -1;
  }
  int pivot = arr[low + (high - low) / 2];
  
  int i = low - 1;
  int j = high + 1;

  while (true) {
    do {
      i++;
    } while (arr[i] > pivot);

    do {
      j--;
    } while (arr[j] < pivot);

    if (i >= j) {
      return j;
    }
    Swap(arr[i], arr[j]);
  }
}

void QuickSort(int arr[], int size, int low, int high) {
  if (low < high) {
    int pi = Partition(arr, size, low, high);

    if (pi < low || pi >= high) {
      return;
    }

    QuickSort(arr, size, low, pi);

    QuickSort(arr, size, pi + 1, high);
  }
}

int main() {
  int n = 0;
  if (!(std::cin >> n) || n < 0) {
    return 1;
  }

  auto arr = std::make_unique<int[]>(n);

  for (int i = 0; i < n; ++i) {
    if (!(std::cin >> arr[i])) {
      return 1;
    }
  }

  QuickSort(arr.get(), n, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << '\n';
  }

  return 0;
}