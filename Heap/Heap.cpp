#include <iostream>
#include <string>

class Heap {
 private:
  int* data_;
  int capacity_;
  int size_;

  void Resize() {
    int new_capacity = capacity_ * 2;
    int* new_data = new int[new_capacity];
    for (int i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  Heap() : capacity_(4), size_(0) {
    data_ = new int[capacity_];
  }

  ~Heap() {
    delete[] data_;
  }

  bool IsEmpty() {
    return size_ == 0;
  }

  void ShiftUp(int index) {
    while (index > 0) {
      int parent = (index - 1) / 2;
      if (data_[index] > data_[parent]) {
        int temp = data_[index];
        data_[index] = data_[parent];
        data_[parent] = temp;
        index = parent;
      } else {
        break;
      }
    }
  }

  void ShiftDown(int index) {
    while (true) {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      int bigger = index;

      if (left < size_ && data_[left] > data_[bigger]) {
        bigger = left;
      }
      if (right < size_ && data_[right] > data_[bigger]) {
        bigger = right;
      }
      if (bigger != index) {
        int temp = data_[index];
        data_[index] = data_[bigger];
        data_[bigger] = temp;
        index = bigger;
      } else {
        break;
      }
    }
  }

  void Push(int value) {
    if (size_ == capacity_) {
      Resize();
    }
    data_[size_] = value;
    ShiftUp(size_);
    ++size_;
  }

  int GetMax() {
    return data_[0];
  }

  void PopMax() {
    if (size_ == 0) {
      return;
    }
    data_[0] = data_[size_ - 1];
    --size_;
    if (size_ > 0) {
      ShiftDown(0);
    }
  }

  void MakeHeap(int* array, int n) {
    delete[] data_;
    capacity_ = (n > 0) ? n : 4;
    data_ = new int[capacity_];
    size_ = n;
    for (int i = 0; i < size_; ++i) {
      data_[i] = array[i];
    }
    for (int i = size_ / 2 - 1; i >= 0; --i) {
      ShiftDown(i);
    }
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  int* array = new int[n > 0 ? n : 1];
  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
  }

  Heap heap;
  heap.MakeHeap(array, n);
  delete[] array;

  int m = 0;
  std::cin >> m;

  for (int i = 0; i < m; ++i) {
    std::string operation;
    std::cin >> operation;

    if (operation == "GetMax") {
      if (heap.IsEmpty()) {
        std::cout << "None\n";
      } else {
        std::cout << heap.GetMax() << '\n';
      }
    } else if (operation == "PopMax") {
      heap.PopMax();
    } else if (operation == "Push") {
      int value = 0;
      std::cin >> value;
      heap.Push(value);
    } else if (operation == "IsEmpty") {
      std::cout << (heap.IsEmpty() ? "TRUE" : "FALSE") << '\n';
    }
  }
  return 0;
}