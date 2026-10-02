#include <iostream>

struct Node {
  int key_;
  int height_;
  Node* left_;
  Node* right_;

  Node(int k) : key_(k), height_(1), left_(nullptr), right_(nullptr) {}
};

class AVLTree{
 private:
  Node* root_;

  int Height(Node* n) {
    return (n ? n->height_ : 0);
  }

  int BalanceFactor(Node* n) {
    return (n ? (Height(n->left_) - Height(n->right_)) : 0);
  }

  void UpdateHeight(Node* n) {
    if (n) {
      int h_left = Height(n->left_);
      int h_right = Height(n->right_);
      if (h_left > h_right) {
        n->height_ = h_left + 1;
      } else {
				n->height_ = h_right + 1;
			}
    }
  }

	Node* RotateRight(Node* y) {
		if (!y || !y->left_) {
			return y;
		}
		Node* x = y->left_;
		Node* T2 = x->right_;
		x->right_ = y;
		y->left_ = T2;
		UpdateHeight(y);
		UpdateHeight(x);
		return x;
	}

	Node* RotateLeft(Node* x) {
		if (!x || !x->right_) {
			return x;
		}
		Node* y = x->right_;
		Node* T2 = y->left_;
		y->left_ = x;
		x->right_ = T2;
		UpdateHeight(x);
		UpdateHeight(y);
		return y;
	}

	Node* Balance(Node* n) {
		UpdateHeight(n);
		int bf = BalanceFactor(n);

		if (bf > 1) {
			if (BalanceFactor(n->left_) < 0) {
				n->left_ = RotateLeft(n->left_);
			}
			return RotateRight(n);
		}

		if (bf < -1) {
			if (BalanceFactor(n->right_) > 0) {
				n->right_ = RotateRight(n->right_);
			}
			return RotateLeft(n);
		}
		return n;
	}

	Node* Insert(Node* n, int key) {
		if (!n) {
			return new Node(key);
		}
		if (key < n->key_) {
			n->left_ = Insert(n->left_, key);
		} else if (key > n->key_) {
			n->right_ = Insert(n->right_, key);
		} else {
			return n;
		}
		return Balance(n);
	}

	Node* FindMin(Node* n) {
		while (n->left_) {
			n = n->left_;
		}
		return n;
	}

	Node* RemoveMin(Node* n) {
		if (!n->left_) {
			return n->right_;
		}
		n->left_ = RemoveMin(n->left_);
		return Balance(n);
	}

	Node* Remove(Node* n, int key) {
		if (!n) {
			return nullptr;
		}
		if (key < n->key_) {
			n->left_ = Remove(n->left_, key);
		} else if (key > n->key_) {
			n->right_ = Remove(n->right_, key);
		} else {
			Node* left = n->left_;
			Node* right = n->right_;
			delete n;

			if (!right) {
				return left;
			}

			Node* minNode = FindMin(right);
			minNode->right_ = RemoveMin(right);
			minNode->left_ = left;
			return Balance(minNode);
		}
		return Balance(n);
	}

	bool Find(Node* n, int key) {
		while (n) {
			if (key == n->key_) {
				return true;
			} else if (key < n->key_) {
				n = n->left_;
			} else {
				n = n->right_;
			}
		}
		return false;
	}

	void Destroy(Node* n) {
		if (!n) {
			return;
		}
		Destroy(n->left_);
		Destroy(n->right_);
		delete n;
	}

 public:
  AVLTree() : root_(nullptr) {}
	
	~AVLTree() {
		Destroy(root_);
	}

	void Push(int key) {
		root_ = Insert(root_, key);
	}

	void Pop(int key) {
		root_ = Remove(root_, key);
	}

	bool Find(int key) {
		return Find(root_, key);
	}

	int GetMin() {
		Node* n = root_;
		if (!n) {
			return 0;
		}
		while (n->left_) {
			n = n->left_;
		}
		return n->key_;
	}

	int GetMax() {
		Node* n = root_;
		if (!n) {
			return 0;
		}
		while (n->right_) {
			n = n->right_;
		}
		return n->key_;
	}
};

int main() {
	AVLTree tree;
	int n = 0;
	std::cin >> n;

	char command[16];
	int element = 0;

	for (int i = 0; i < n; ++i) {
		std::cin >> command;
		if (command[0] == 'p' && command[1] == 'u') {
			std::cin >> element;
			tree.Push(element);
		} else if (command[0] == 'p' && command[1] == 'o') {
			std::cin >> element;
			tree.Pop(element);
		} else if (command[0] == 'f') {
			std::cin >> element;
			std::cout << (tree.Find(element) ? "TRUE" : "FALSE") << '\n';
		} else if (command[0] == 'g' && command[6] == 'n') {
			std::cout << tree.GetMin() << '\n';
		} else if (command[0] == 'g' && command[6] == 'x') {
			std::cout << tree.GetMax() << '\n';
 		}
	}
	return 0;
}