#include <iostream>

bool Comparator(int x, int y) {
  return x > y;
}

void Merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int* left_arr = new int[n1];
  int* right_arr = new int[n2];

  for (int i = 0; i < n1; ++i) {
    left_arr[i] = arr[left + i];
  }

  for (int i = 0; i < n2; ++i) {
    right_arr[i] = arr[mid + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (Comparator(left_arr[i], right_arr[j])) {
      arr[k] = left_arr[i];
      i++;
    } else {
      arr[k] = right_arr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left_arr[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right_arr[j];
    j++;
    k++;
  }
  delete[] left_arr;
  delete[] right_arr;
}

void MergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    Merge(arr, left, mid, right);
  }
}

int main() {
  int n = 0;
  std::cin >> n;

  int* arr = new int[n];

  for (int i =0; i < n; ++i) {
    std::cin >> arr[i];
  }

  MergeSort(arr, 0, n -1);

  for (int i = 0; i < n; ++i) {
    std::cout << '\n' << arr[i] << '\n';
  }
  delete[] arr;
  return 0;
}