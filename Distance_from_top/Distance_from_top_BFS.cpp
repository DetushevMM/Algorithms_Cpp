#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n = 0;
  int m = 0;
  int s = 0;

  std::cin >> n >> m >> s;

  std::vector<std::vector<int>> adjacency_list(n + 1);

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;

    std::cin >> u >> v;
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  std::vector<int> distance(n + 1, -1);
  std::queue<int> q;

  distance[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adjacency_list[u]) {
      if (distance[v] == -1) {
        distance[v] = distance[u] + 1;
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << distance[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}