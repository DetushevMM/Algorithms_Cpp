#include <iostream>
#include <string>

class Stack {
 private:
  int* data_;
  int capacity_;
  int top_;

 public:
  explicit Stack(int size = 1000) {
    capacity_ = size;
    data_ = new int[capacity_];
    top_ = -1;
  }

  ~Stack() {
    delete[] data_;
  }

  void Push(int value) {
    if (top_ < capacity_ - 1) {
        data_[++top_] = value;
    }
  }

  int Pop() {
    if (top_ >= 0) {
        return data_[top_--];
    }
    return 0;
  }

  int Top() {
    if (top_ >= 0) {
        return data_[top_];
    }
    return 0;
  }

  bool IsEmpty() {
    return top_ == -1;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  Stack stack(n);

  for (int i = 0; i < n; ++i) {
    std::string token;
    std::cin >> token;

    if (token == "+") {
      int b = stack.Pop();
      int a = stack.Pop();
      stack.Push(a + b);
    } else if (token == "-") {
      int b = stack.Pop();
      int a = stack.Pop();
      stack.Push(a - b);
    } else if (token == "*") {
      int b = stack.Pop();
      int a = stack.Pop();
      stack.Push(a * b);
    } else if (token == ":") {
      int b = stack.Pop();
      int a = stack.Pop();
      stack.Push(a / b);
    } else {
      int number = std::stoi(token);
      stack.Push(number);
    }
  }
  std::cout << stack.Top() << '\n';

  return 0;
}