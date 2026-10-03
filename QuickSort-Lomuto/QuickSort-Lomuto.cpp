#include <iostream>
#include <vector>

void Swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

int Partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high];

  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (arr[j] > pivot) {
      i++;
      Swap(arr[i], arr[j]);
    }
  }

  Swap(arr[i + 1], arr[high]);
  return i + 1;
}

void QuickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = Partition(arr, low, high);

    QuickSort(arr, low, pi - 1);

    QuickSort(arr, pi + 1, high);
  }
}

int main() {
  int n = 0;
  if (!(std::cin >> n) || n < 0) {
    return 1;
  }

  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    if (!(std::cin >> arr[i])) {
      return 1;
    }
  }

  if (n > 1) {
    QuickSort(arr, 0, n - 1);
  }

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << '\n';
  }

  return 0;
}