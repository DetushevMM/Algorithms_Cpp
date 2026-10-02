#include <iostream>
#include <cstring>

class Stack {
 private:
  char* data_;
  int capacity_;
  int top_;

 public:
  explicit Stack(int capacity = 1000) {
    capacity_ = capacity;
    data_ = new char[capacity_];
    top_ = -1;
  }

  ~Stack() {
    delete[] data_;
  }

  void Push(char symbol) {
    if (top_ < capacity_ - 1) {
      data_[++top_] = symbol;
    }
  }

  char Pop() {
    if (top_ >= 0) {
      return data_[top_--];
    }
    return '\0';
  }

  char Peek() {
    if (top_ >= 0) {
      return data_[top_];
    }
    return '\0';
  }

  bool IsEmpty() {
    return top_ == -1;
  }
};

bool IsOpen(char bracket) {
  return bracket == '(' || bracket == '[' || bracket == '{';
}

bool IsClose(char bracket) {
  return bracket == ')' || bracket == '}' || bracket == ']';
}

bool IsMatching(char open, char close) {
  return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}


int main() {
  char str[1000];
  std::cin >> str;

  Stack stack;
  size_t len = strlen(str);

  for (size_t i = 0; i < len; ++i) {
    char c = str[i];

    if (IsOpen(c)) {
      stack.Push(c);
    } else if (IsClose(c)) {
      if (stack.IsEmpty()) {
        std::cout << "INCORRECT\n";
        return 0;
      }
      char opening = stack.Pop();
      if (!IsMatching(opening, c)) {
        std::cout << "INCORRECT\n";
        return 0;
      }
    }
  }
  if (stack.IsEmpty()) {
    std::cout << "CORRECT\n"; 
  } else {
    std::cout << "INCORRECT\n";
  }
  return 0;
}