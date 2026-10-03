// Метод одномерного динамического программирования, согласно условию задачи.

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

    data_[size_] = value;
    ++size_;
  }

  int GetSize() const {
    return size_;
  }

  int& operator[](int index) {
    return data_[index];
  }

  const int& operator[](int index) const {
    return data_[index];
  }
};

int main() {
  int max_weight = 0;
  int n = 0;

  std::cin >> max_weight;
  std::cin >> n;

  DynamicArray weights;

  for (int i = 0; i < n; ++i) {
    int weight = 0;
      std::cin >> weight;
      weights.PushBack(weight);
  }

  // dp[w] — максимальное количество предметов, которое можно взять при грузоподъёмности w.
  int* dp = new int[max_weight + 1];

  // Изначально все значения равны 0.
  for (int w = 0; w <= max_weight; ++w) {
    dp[w] = 0;
  }

  // Обрабатываем каждый предмет один раз.
  for (int i = 0; i < n; ++i) {
    int weight = weights[i];

    // В нормальной постановке задачи масса предмета положительна и не превышает грузоподъёмность рюкзака.
    if (weight <= 0 || weight > max_weight) {
      continue;
    }

    // Идём справа налево, чтобы предмет нельзя было взять повторно.
    for (int w = max_weight; w >= weight; --w) {
      if (dp[w - weight] + 1 > dp[w]) {
        dp[w] = dp[w - weight] + 1;
      }
    }
  }

  std::cout << dp[max_weight] << '\n';

  delete[] dp;

  return 0;
}