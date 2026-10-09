#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  // Список смежности: для каждой вершины храним вектор соседей
  std::vector<std::vector<int>> adjacency_list(n + 1);

  for (int i = 0; i < m; i++) {
    int u = 0;
    int v = 0;
        
    std::cin >> u >> v;
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);  // граф неориентированный
  }

  // BFS из вершины 1
  std::vector<bool> visited(n + 1, false);
  std::vector<int> queue;   // используем vector как очередь
  queue.push_back(1);
  visited[1] = true;

  int count = 0;  // количество посещённых вершин
  int head = 0;  // индекс "головы" очереди (откуда извлекаем)

  while (head < queue.size()) {
    int v = queue[head++];  // извлекаем вершину из головы
    count++;

    // Просматриваем всех соседей
    for (int i = 0; i < adjacency_list[v].size(); i++) {
      int u = adjacency_list[v][i];
      if (!visited[u]) {
        visited[u] = true;
        queue.push_back(u);  // добавляем в хвост очереди
      }
    }
  }

  // Граф связный, если обошли все N вершин
  if (count == n) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  return 0;
}