#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n = 0;
  int m = 0;
  int s = 0;
  int t = 0;
  std::cin >> n >> m >> s >> t;

  std::vector<std::vector<int>> adjacency_list(n + 1);

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }
  std::vector<int> distance(n + 1, -1);
  std::vector<int> parent(n + 1, -1);

  std::queue<int> queue;
  queue.push(s);
  distance[s] = 0;

  while (!queue.empty()) {
    int v = queue.front();
    queue.pop();

    for (int to : adjacency_list[v]) {
      if (distance[to] == -1) {
        distance[to] = distance[v] + 1;
        parent[to] = v;
        queue.push(to);
      }
    }
  }

  if (distance[t] == -1) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::vector<int> path;
  int current = t;

  while (current != -1) {
    path.push_back(current);
    current = parent[current];
  }

  std::cout << distance[t] << '\n';
  for (int i = (int)path.size() - 1; i >= 0; --i) {
    std::cout << path[i];
    if (i > 0) {
      std::cout << ' ';
    }
  }
  std::cout << '\n';

  return 0;
}