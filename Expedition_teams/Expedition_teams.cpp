#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  // Список смежности: для каждой вершины храним список соседей
  std::vector<std::vector<int>> adjacency_list(n + 1);

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  // Массив посещённых вершин
  std::vector<bool> visited(n + 1, false);

  int groups = 0;
  for (int start = 1; start <= n; ++start) {
    if (visited[start]) {
      continue;
    }
    // Начинаем новую группу — обходим все достижимые вершины (DFS)
    ++groups;

    std::vector<int> stack;
    stack.push_back(start);
    visited[start] = true;

    while (!stack.empty()) {
      int u = stack.back();
      stack.pop_back();

      for (int i = 0; i < adjacency_list[u].size(); ++i) {
        int v = adjacency_list[u][i];
        if (!visited[v]) {
          visited[v] = true;
          stack.push_back(v);
        }
      }
    }
  }
  std::cout << groups << '\n';

  return 0;
}