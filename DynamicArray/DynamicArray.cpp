#include <iostream>

class DynamicArray {
 private:
  int* data_;
  int size_;
  int capacity_;

  void Resize() {
    int new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    int* new_data = new int[new_capacity];

    for (int i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  DynamicArray() : data_(nullptr), size_(0), capacity_(0) {}
  
  ~DynamicArray() {
    delete[] data_;
  }

  void PushBack(int elem) {
    if (size_ >= capacity_) {
      Resize();
    }
    data_[size_] = elem;
    size_++;
  }

  int PopBack() {
    if (size_ == 0) {
      return 0;
    }
    int removed = data_[size_ - 1];
    size_--;
    return removed;
  }

  int Size() const {
    return size_;
  }

  int Capacity() const {
    return capacity_;
  }

  int& operator[](int index) const {
    return data_[index];
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  DynamicArray arr;
  std::string command;

  for (int i = 0; i < n; ++i) {
    std::cin >> command;

    if (command == "push_back") {
      int value = 0;
      std::cin >> value;
      arr.PushBack(value);
    } else if (command == "pop_back") {
      std::cout << arr.PopBack() << '\n';
    } else if (command == "size") {
      std::cout << arr.Size() << '\n';
    } else if (command == "index") {
      int index = 0;
      std::cin >> index;
      std::cout << arr[index] << '\n';
    }
  }

  return 0;
}