// Метод сортировки + жадный алгоритм

#include <iostream>


class DynamicArray {
 private:
  int* data_;
  int size_;
  int capacity_;

 public:
  DynamicArray() : data_(nullptr), size_(0), capacity_(0) {}

  ~DynamicArray() {
    delete[] data_;
  }

  void PushBack(int value) {
    if (size_ >= capacity_) {
      int new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
      int* new_data = new int[new_capacity];
      for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
      capacity_ = new_capacity;
    }
    data_[size_++] = value;
  }

  int& operator[](int index) {
    return data_[index];
  }

  const int& operator[](int index) const {
    return data_[index];
  }

  int GetSize() const {
    return size_;
  }
};

void SortArray(DynamicArray& arr) {
  int n = arr.GetSize();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int max_weight = 0;
  std::cin >> max_weight;
  if (max_weight < 0) {
    return 1;
  }
  int n = 0;
  std::cin >> n;

  DynamicArray weights;

  for (int i = 0; i < n; ++i) {
    int w = 0;
    std::cin >> w;
    weights.PushBack(w);
  }

  SortArray(weights);

  int count = 0;
  int current = 0;
  for (int i = 0; i < weights.GetSize(); ++i) {
    if (current + weights[i] <= max_weight) {
      current += weights[i];
      count++;
    } else {
      break;
    }
  }
  std::cout << count << '\n';

  return 0;
}