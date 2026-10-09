// Итеративный метод обхода графа без STL

#include <iostream>

const int MAX_N = 1000;

int main() {
  int n = 0;
  int m = 0;
  int s = 0;
  std::cin >> n >> m >> s;
    
  // Матрица смежности (0/1)
  static bool adjacency_matrix[MAX_N + 1][MAX_N + 1] = {};
    
  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    adjacency_matrix[u][v] = true;
    adjacency_matrix[v][u] = true;
  }
    
  // Стек для DFS
  int stack[MAX_N];
  int stackSize = 0;
    
  // Посещённые вершины
  static bool visited[MAX_N + 1] = {};
    
  // Порядок посещения
  int order[MAX_N];
  int orderSize = 0;
    
  // Начинаем с S
  stack[stackSize++] = s;
    
  while (stackSize > 0) {
    int v = stack[--stackSize];
        
    if (visited[v]) {
      continue;
    }
    visited[v] = true;
    order[orderSize++] = v;
        
    // Кладём в стек соседей в порядке убывания номеров, чтобы при извлечении они шли по возрастанию
    for (int u = n; u >= 1; --u) {
      if (adjacency_matrix[v][u] && !visited[u]) {
        stack[stackSize++] = u;
      }
    }
  }

  for (int i = 0; i < orderSize; ++i) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << order[i];
  }
  std::cout << '\n';
    
  return 0;
}