#include <iostream>

class Stack {
 private:
  int* data_;
  int capacity_;
  int top_;

  void Resize() {
    int new_capacity = capacity_ * 2;
    int* new_data = new int[new_capacity];
    for (int i = 0; i < top_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  Stack() : capacity_(10), top_(0) {
    data_ = new int[capacity_];
  }

  ~Stack() {
    delete[] data_;
  }

  void Push(int elem) {
    if (top_ == capacity_) {
      Resize();
    }
    data_[top_] = elem;
    top_++;
  }

  bool IsEmpty() {
    return top_ == 0;
  }

  void Pop() {
    if (!IsEmpty()) {
      top_--;
    }
  }

  int Top() {
    return data_[top_ - 1];
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  Stack stack;
  std::string command;

  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "push") {
      int value = 0;
      std::cin >> value;
      stack.Push(value);
    } else if (command == "pop") {
      stack.Pop();
    } else if (command == "top") {
      std::cout << stack.Top() << '\n';
    } else if (command == "is_empty") {
      if (stack.IsEmpty()) {
        std::cout << "Пуст\n";
      } else {
        std::cout << "Не пуст\n";
      }
    }
  }
  return 0;
}