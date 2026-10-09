// Итеративный обход графа с использованием STL

#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  int s = 0;
  std::cin >> n >> m >> s;

  // Матрица смежности (n+1, чтобы индексация была с 1)
  std::vector<std::vector<bool>> adjacency_matrix(n + 1, std::vector<bool>(n + 1, false));

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    adjacency_matrix[u][v] = true;
    adjacency_matrix[v][u] = true;
  }

  std::vector<bool> visited(n + 1, false);

  // Стек для итеративного DFS
  std::vector<int> stack;
  stack.reserve(n);
  stack.push_back(s);

  std::vector<int> order;
  order.reserve(n);

  while (!stack.empty()) {
    int v = stack.back();
    stack.pop_back();

    if (visited[v]) {
      continue;
    }
    visited[v] = true;
    order.push_back(v);

    // Кладём соседей в порядке убывания номеров, чтобы извлекались они по возрастанию
    for (int u = n; u >= 1; --u) {
      if (adjacency_matrix[v][u] && !visited[u]) {
        stack.push_back(u);
      }
    }
  }

  for (int i = 0; i < order.size(); ++i) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << order[i];
  }
  std::cout << '\n';

  return 0;
}