// Рекурсивный обход графа

#include <iostream>
#include <vector>

std::vector<std::vector<bool>> adjacency_matrix;
std::vector<bool> visited;
bool first = true;

void DFS(int v) {
  visited[v] = true;
  if (!first) {
    std::cout << ' ';
  }
  first = false;
  std::cout << v;

  for (int u = 1; u <= (int)adjacency_matrix.size() - 1; ++u) {
    if (adjacency_matrix[v][u] && !visited[u]) {
      DFS(u);
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  int s = 0;
  std::cin >> n >> m >> s;

  adjacency_matrix.assign(n + 1, std::vector<bool>(n + 1, false));
  visited.assign(n + 1, false);

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    adjacency_matrix[u][v] = true;
    adjacency_matrix[v][u] = true;
  }

  DFS(s);
  std::cout << '\n';
  
  return 0;
}