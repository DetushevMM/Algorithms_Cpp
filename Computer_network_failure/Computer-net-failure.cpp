#include <iostream>

int main() {
  int n = 0;
  int m = 0;
  int s = 0;

  std::cin >> n >> m >> s;

  // Статический массив - Матрица смежности (N+1)x(N+1) = 1001 х 1001
  bool massive[1001][1001] = {false};

  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;

    std::cin >> u >> v;
    massive[u][v] = true;
    massive[v][u] = true;
  }

  int k = 0;
  std::cin >> k;

  bool off[1001] = {false};

  for (int i = 0; i < k; i++) {
    int x = 0;
    std::cin >> x;
    off[x] = true;
  }

  // DFS 
  bool visited[1001] = {false};
  int stack[1001];
  int top = 0;

  visited[s] = true;
  stack[top++] = s;
  
  int count = 0;

  while(top > 0) {
    int current = stack[--top];
    count++;

    for(int v = 1; v <= n; ++v) {
      if (massive[current][v] && (!visited[v]) && (!off[v])) {
        visited[v] = true;
        stack[top++] = v;
      }
    }
  }
  std::cout << count << '\n';
  return 0;
}