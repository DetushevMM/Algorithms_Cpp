#include <iostream>
#include <string>

template <class T>
class Stack {
 private:
  T* data_;
  int capacity_;
  int top_;

 public:
  Stack() : capacity_(10), top_(-1) {
    data_ = new T[capacity_];
  }

  ~Stack() {
    delete[] data_;
  }

  void Push(const T& elem) {
    if (top_ + 1 >= capacity_) {
      capacity_ *= 2;
      T* new_data = new T[capacity_];
      for (int i = 0; i <= top_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
    }
    data_[++top_] = elem;
  }

  bool IsEmpty() const {
    return top_ == -1;
  }
  void Pop() {
    if (!IsEmpty()) {
      --top_;
    }
  }

  T Top() const {
    return data_[top_];
  }
};

template <class T>
class Queue {
 private:
  Stack<T> input_stack_;
  Stack<T> output_stack_;

  void Transfer() {
    while (!input_stack_.IsEmpty()) {
      output_stack_.Push(input_stack_.Top());
      input_stack_.Pop();
    }
  }

 public:
  void Push(const T& element) {
    input_stack_.Push(element);
  }

  bool IsEmpty() const {
    return input_stack_.IsEmpty() && output_stack_.IsEmpty();
  }

  void Pop() {
    if (output_stack_.IsEmpty()) {
      Transfer();
    }
    if (!output_stack_.IsEmpty()) {
      output_stack_.Pop();
    }
  }

  T Top() {
    if (output_stack_.IsEmpty()) {
      Transfer();
    }
    return output_stack_.Top();
  }
};

int main() {
  Queue<std::string> queue;
  std::string command;
  bool end_of_shift = false;

  while (std::getline(std::cin, command)) {
    if (command == "Смена закончилась!") {
      break;
    }
    if (command == "новичок:") {
      std::string name;
      std::cin >> name;
      queue.Push(name);
    } else if (command == "следующий") {
      if (queue.IsEmpty()) {
        std::cout << "Все вылечены!\n";
        return 0;
      }
      std::cout << queue.Top() << '\n';
      queue.Pop();

      if (queue.IsEmpty()) {
        std::cout << "Все вылечены!\n";
        return 0;
      }
    }
  }
  return 0;
}