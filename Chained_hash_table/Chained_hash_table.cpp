#include <iostream>
#include <cstring>

struct Node {
  char* str;
  Node* next;

  explicit Node(const char* s) {
    size_t len = strlen(s);
    str = new char[len + 1];
    std::memcpy(str, s, len);
    str[len] = '\0';
    next = nullptr;
  }

  ~Node() {
    delete[] str;
  }
};

class HashTable {
 private:
  static const int kTableSize = 10007;
  static const int BASE = 31;
  Node** table;

  // Полиномиальная хеш функция
  size_t PolyHash(const char* str) const {
    size_t h = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
      h = h * BASE + (unsigned char)str[i];
    }
    return h % kTableSize;
  }

 public:
  HashTable() {
    table = new Node*[kTableSize]{nullptr};
  }

  ~HashTable() {
    for (int i = 0; i < kTableSize; ++i) {
      Node* current = table[i];
      while (current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
      }
    }
    delete[] table;
  }

  void Push(const char* str) {
    size_t index = PolyHash(str);

    Node* current = table[index];
    while (current != nullptr) {
      if (std::strcmp(current->str, str) == 0) {
        return;
      }
      current = current->next;
    }
    Node* newNode = new Node(str);
    newNode->next = table[index];
    table[index] = newNode;
  }

  bool Pop(const char* str) {
    size_t index = PolyHash(str);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr) {
      if (strcmp(current->str, str) == 0) {
        if (prev == nullptr) {
          table[index] = current->next;
        } else {
          prev->next = current->next;
        }
        delete current;
        return true;
      }
      prev = current;
      current = current->next;
    }
    return false;
  }

  bool Search(const char* str) {
    size_t index = PolyHash(str);
    Node* current = table[index];

    while (current != nullptr) {
      if (strcmp(current->str, str) == 0) {
        return true;
      }
      current = current->next;
    }
    return false;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  HashTable ht;
  char command[20];
  char str[100001];

  for (int i = 0; i < n; ++i) {
    std::cin >> command >> str;

    if (strcmp(command, "push") == 0) {
      ht.Push(str);
    } else if (strcmp(command, "pop") == 0) {
      if (ht.Pop(str)) {
        std::cout <<  "TRUE\n";
      } else {
        std::cout << "FALSE\n";
      }
    } else if (strcmp(command, "search") == 0) {
      if (ht.Search(str)) {
        std::cout << "TRUE\n";
      } else {
       std::cout << "FALSE\n";
     }
    }
  }
  return 0;
}