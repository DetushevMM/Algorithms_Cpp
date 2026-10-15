#include <iostream>
#include <vector>
#include <queue>

struct Edge {
  int to_;
  long long w_;
};

int main() {
  int n = 0;
  int m = 0;
  int s = 0;
  int t = 0;
  std::cin >> n >> m >> s >> t;

  std::vector<std::vector<Edge>> graph(n + 1);

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    long long w = 0;
    std::cin >> u >> v >> w;

    graph[u].push_back({v, w});
  }
  
  const long long INF = 1e18;

  std::vector<long long> distance(n + 1, INF);
  std::vector<int> parent(n + 1, 0);

  std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

  distance[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    std::pair<long long, int> top = pq.top();
    pq.pop();

    long long d = top.first;
    int u = top.second;

    if (d > distance[u]) {
      continue;
    }
    for (size_t i = 0; i < graph[u].size(); ++i) {
      const Edge& e = graph[u][i];
      if (distance[u] + e.w_ < distance[e.to_]) {
        distance[e.to_] = distance[u] + e.w_;
        parent[e.to_] = u;
        pq.push({distance[e.to_], e.to_});
      }
    }
  }

  if (distance[t] == INF) {
    std::cout << -1 << '\n';
    return 0;
  }

  // Восстановление пути
  std::vector<int> path;
  int current = t;

  while (current != 0) {
    path.push_back(current);

    if (current == s) {
      break;
    }
    current = parent[current];
  }

  // Разворот вручную
  int k = path.size();
  for (int i = 0; i < (k / 2); ++i) {
    int temp = path[i];
    path[i] = path[k - 1 -i];
    path[k - 1 - i] = temp;
  }

  std::cout << distance[t] << '\n';
  std::cout << k << '\n';

  for (int i = 0; i < k; ++i) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << path[i];
  }
  std::cout << '\n';

  return 0;
}