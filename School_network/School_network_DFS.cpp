#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  // Список смежности: для каждой вершины храним вектор соседей
  std::vector<std::vector<int>> adjacency_list(n + 1);

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;

    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  // Итеративный DFS из вершины 1
  std::vector<bool> visited(n + 1, false);
  std::vector<int> stack;
  stack.push_back(1);
  visited[1] = true;
  int count = 0;

  while(!stack.empty()) {
    int v = stack.back();
    stack.pop_back();
    count++;

    for (int u : adjacency_list[v]) {
      if (!visited[u]) {
        visited[u] = true;
        stack.push_back(u);
      }
    }
  }
  // Граф связный, если обошли все N вершин
  std::cout << (count == n ? "YES" : "NO") << '\n';

  return 0;
}