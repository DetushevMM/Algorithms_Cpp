#include <iostream>
#include <cstdlib>

struct Node {
  int key_;
  int priority_;
  Node* left_;
  Node* right_;

  Node(int key, int pr) : key_(key), priority_(pr), left_(nullptr), right_(nullptr) {}
};

class DecartTree {
 private:
  Node* root_;

  // Разбиение дерева на два поддерева: элементы < key и элементы >= key
  void Split(Node* node, int key, Node*& left, Node*& right) {
    if (node == nullptr) {
      left = nullptr;
      right = nullptr;
      return;
    }
    if (node->key_ < key) {
      Split(node->right_, key, node->right_, right);
      left = node;
    } else {
      Split(node->left_, key, left, node->left_);
      right = node;
    }
  }

  // Слияние двух деревьев (все ключи left < все ключи right)
  Node* Merge(Node* left, Node* right) {
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
    if (left->priority_ > right->priority_) {
      left->right_ = Merge(left->right_, right);
      return left;
    } else {
      right->left_ = Merge(left, right->left_);
      return right;
    }
  }

  Node* FindMin(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    while (node->left_ != nullptr) {
      node = node->left_;
    }
    return node;
  }

  Node* FindMax(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    while (node->right_ != nullptr) {
      node = node->right_;
    }
    return node;
  }

  bool Find(Node* node, int key) {
    if (node == nullptr) {
      return false;
    }
    if (node->key_ == key) {
      return true;
    }
    if (key < node->key_) {
      return Find(node->left_, key);
    }
    return Find(node->right_, key);
  }

  void DestroyTree(Node* node) {
    if (node != nullptr) {
      DestroyTree(node->left_);
      DestroyTree(node->right_);
      delete node;
    }
  }

 public:
  DecartTree() : root_(nullptr) {}

  ~DecartTree() {
    DestroyTree(root_);
  }

  void Push(int key) {
    if (Find(root_, key)) {  // Если есть такое - не добавляем дубликаты
      return;
    }
    int priority = std::rand();
    Node* new_node = new Node(key, priority);

    Node* left;
    Node* right;
    Split(root_, key, left, right);
    root_ = Merge(Merge(left, new_node), right);
  }

  void Pop(int key) {
    if (!Find(root_, key)) {
      return;
    }

    Node* left;
    Node* right;
    Node* mid;

    Split(root_, key, left, right);
    Split(right, key + 1, mid, right);

    DestroyTree(mid);

    root_ = Merge(left, right);
  }

  bool Find(int key) {
    return Find(root_, key);
  }

  int GetMin() {
    Node* min_node = FindMin(root_);
    if (min_node == nullptr) {
      return 0;
    }
    return min_node->key_;
  }

  int GetMax() {
    Node* max_node = FindMax(root_);
    if (max_node == nullptr) {
      return 0;
    }
    return max_node->key_;
  }

  bool Empty() {
    return root_ == nullptr;
  }
};

int main() {
  std::srand(12345);

  DecartTree tree;
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    char command[20];
    std::cin >> command;

    if (command[0] == 'p' && command[1] == 'u') {
      int key = 0;
      std::cin >> key;
      tree.Push(key);
    } else if (command[0] == 'p' && command[1] == 'o') {
      int key = 0;
      std::cin >> key;
      tree.Pop(key);
    } else if (command[0] == 'f') {
      int key = 0;
      std::cin >> key;
      if (tree.Find(key)) {
        std::cout << "TRUE\n";
      } else {
        std::cout << "FALSE\n";
      }
    } else if (command[0] == 'g' && command[6] == 'n') {
      if (!tree.Empty()) {
        std::cout << tree.GetMin() << '\n';
      }
    } else if (command[0] == 'g' && command[6] == 'x') {
      if (!tree.Empty()) {
        std::cout << tree.GetMax() << '\n';
      }
    }
  }
  return 0;
}