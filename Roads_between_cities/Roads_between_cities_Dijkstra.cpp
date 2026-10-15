// Алгоритм Дейкстры
#include <iostream>

const long long INF = 1e18;

// Реализация минимальной бинарной кучи
struct HeapNode {
  long long distance_;
  int vertex_;
};

class MinHeap {
 private:
  HeapNode* data_;
  int size_;
  int capacity_;

  void SwapNodes(int i, int j) {
    HeapNode temp = data_[i];
    data_[i] = data_[j];
    data_[j] = temp;
  }

  void SiftUp(int i) {
    while (i > 0) {
      int parent = (i - 1) / 2;
      if (data_[parent].distance_ <= data_[i].distance_) {
        break;
      }
      SwapNodes(parent, i);
      i = parent;
    }
  }

  void SiftDown(int i) {
    while (true) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int smallest = i;

      if (left < size_ && data_[left].distance_ < data_[smallest].distance_) {
        smallest = left;
      }
      if (right < size_ && data_[right].distance_ < data_[smallest].distance_) {
        smallest = right;
      }
      if (smallest == i) {
        break;
      }
      SwapNodes(i, smallest);
      i = smallest;
    }
  }

 public:
  MinHeap(int cap) {
    capacity_ = cap;
    size_ = 0;
    data_ = new HeapNode[cap];
  }

  ~MinHeap() {
    delete[] data_;
  }

  bool Empty() const {
    return size_ == 0;
  }

  void Push(long long d, int v) {
    if (size_ == capacity_) {
      return;
    }
    data_[size_].distance_ = d;
    data_[size_].vertex_ = v;
    size_++;
    SiftUp(size_ - 1);
  }

  HeapNode Pop() {
    HeapNode top = data_[0];
    data_[0] = data_[size_ - 1];
    size_--;
    if (size_ > 0) {
      SiftDown(0);
    }
    return top;
  }
};

// Односвязный список для рёбер
struct Edge {
  int to_;
  long long weight_;
  Edge* next;
};

int main() {
  int n = 0;
  int m = 0;
  int s = 0;
  int t = 0;
  std::cin >> n >> m >> s >> t;

  // head[i] — указатель на начало списка рёбер из вершины i
  Edge** head = new Edge*[n + 1];
  for (int i = 0; i <= n; ++i) {
    head[i] = nullptr;
  }

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    long long w = 0;
    std::cin >> u >> v >> w;

    Edge* e_1 = new Edge{v, w, head[u]};
    head[u] = e_1;

    Edge* e_2 = new Edge{u, w, head[v]};
    head[v] = e_2;
  }

  long long* distance = new long long[n + 1];
  bool* visited = new bool[n + 1];

  for (int i = 0; i <= n; ++i) {
    distance[i] = INF;
    visited[i] = false;
  }

  MinHeap heap(m * 2 + 5);
  distance[s] = 0;
  heap.Push(0, s);

  while (!heap.Empty()) {
    HeapNode node = heap.Pop();
    int u = node.vertex_;
    long long d = node.distance_;

    if (visited[u]) {
      continue;
    }
    visited[u] = true;

    if (u == t) {
      break;
    }

    for (Edge* e = head[u]; e != nullptr; e = e->next) {
      int v = e->to_;
      long long nd = d + e->weight_;

      if (nd < distance[v]) {
        distance[v] = nd;
        heap.Push(nd, v);
      }
    }
  }

  if (distance[t] == INF) {
    std::cout << -1 << '\n';
  } else {
    std::cout << distance[t] << '\n';
  }

  // Освобождение памяти
  for (int i = 0; i <= n; ++i) {
    Edge* e = head[i];
    while (e != nullptr) {
      Edge* next = e->next;
      delete e;
      e = next;
    }
  }
  delete[] head;
  delete[] distance;
  delete[] visited;

  return 0;
}