#include <iostream>

struct Node{
  int value;
  Node* left;
  Node* right;
  
  explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BST {
 private:
  Node* root_;

  void Destroy(Node* node) {
    if (node) {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
  }

  Node* FindNode(Node* node, int element) const {
    if (!node) {
        return nullptr;
    }
    if (node->value == element) {
        return node;
    }
    if (element < node->value) {
        return FindNode(node->left, element);
    }
    return FindNode(node->right, element);
  }

  // Функция проверяет удалён ли элемент и возвращает true, если удалён
  bool Remove(Node*& node, int element) {
    if (!node) {
        return false;
    }
    if (element < node->value) {
        return Remove(node->left, element);
    }
    if (element > node->value) {
        return Remove(node->right, element);
    }

    // Eсли нашли узел
    if(!node->left && !node->right) {
        delete node;
        node = nullptr;
    } else if (!node->left) {
        Node* right_child = node->right;
        delete node;
        node = right_child;
    } else if (!node->right) {
        Node* left_child = node->left;
        delete node;
        node = left_child;
    } else {                                // Ищем минимальный в правом поддереве
        Node* min_node = node->right;
        while (min_node->left) {
          min_node = min_node->left;
        }
        node->value = min_node->value;
        Remove(node->right, min_node->value);
    }
    return true;
  }

 public:
  BST() : root_(nullptr) {};
  
  ~BST() {
    Destroy(root_);
  }

  void Push(int elevent) {
    Node** current = &root_;
    while (*current) {
      if (elevent <= (*current)->value) {
        current = &(*current)->left;
      } else {
        current = &(*current)->right;
      }
    }
    *current = new Node(elevent);
  }

  bool Find(int element) const {
    Node* current = root_;
    while (current) {
      if (element == current->value) {
        return true;
      }
      current = (element < current->value) ? current->left : current->right;
    }
    return false;
  }

  void Pop(int element) {
    Remove(root_, element);
  }

  bool GetMin(int& out) const {
    if (!root_) {
        return false;
    }
    Node* current = root_;
    while (current->left) {
        current = current->left;
    }
    out = current->value;
    return true;
  }

  bool GetMax(int& out) const {
    if (!root_) {
      return false;
    }
    Node* current = root_;
    while (current->right) {
        current = current->right;
    }
    out = current->value;
    return true;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  BST tree;
  for (int i = 0; i < n; ++i) {
    char command[16];
    std::cin >> command;

    if (command[0] == 'p' && command[1] == 'u') {
      int element = 0;
      std::cin >> element;
      tree.Push(element);
    } else if (command[0] == 'p' && command[1] == 'o') {
      int element = 0;
      std::cin >> element;
      tree.Pop(element);
    } else if (command[0] == 'f') {
      int element = 0;
      std::cin >> element;
      std::cout << (tree.Find(element) ? "TRUE" : "FALSE") << '\n';
    } else if (command[0] == 'g' && command[6] == 'n') {
      int value = 0;
      if (tree.GetMin(value)) {
        std::cout << value << '\n';
      }
    } else if (command[0] == 'g' && command[6] == 'x') {
      int value = 0;
      if (tree.GetMax(value)) {
        std::cout << value << '\n';
      }
    }
  }
  return 0;
}