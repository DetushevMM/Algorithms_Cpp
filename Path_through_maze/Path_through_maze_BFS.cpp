#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  std::vector<std::string> maze(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> maze[i];
  }

  // Находим старт
  int start_x = -1;
  int start_y = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 'S') {
        start_x = i;
        start_y = j;
      }
    }
  }

  // BFS
  std::vector<std::vector<int>> distance(n, std::vector<int>(m, -1));
  std::vector<std::pair<int, int>> queue;
  queue.reserve(n * m);

  distance[start_x][start_y] = 0;
  queue.push_back({start_x, start_y});

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  size_t head = 0;

  while (head < queue.size()) {
    int x = queue[head].first;
    int y = queue[head].second;
    ++head;

    if (maze[x][y] == 'F') {
      std::cout << distance[x][y] << '\n';
      return 0;
    }

    for (int d = 0; d < 4; ++d) {
      int n_x = x + dx[d];
      int n_y = y + dy[d];

      if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) {
        continue;
      }
      if (maze[n_x][n_y] == '#') {
        continue;
      }
      if (distance[n_x][n_y] != -1) {
        continue;
      }
      distance[n_x][n_y] = distance[x][y] + 1;
      queue.push_back({n_x, n_y});
    }
  }
  std::cout << -1 << '\n';

  return 0;
}