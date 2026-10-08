#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  std::vector<std::string> map(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> map[i];
  }

  int island = 0;

  // Стек для DFS: храним пары (строка, столбец)
  std::vector<std::pair<int, int>> stack;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == '#') {
        ++island;

        // Запускаем обход острова
        stack.clear();
        stack.push_back({i, j});
        map[i][j] = '.';  // помечаем как посещённую

        while (!stack.empty()) {
          std::pair<int, int> current = stack.back();
          stack.pop_back();

          int r = current.first;
          int c = current.second;

          // Проверяем 4 соседа в графе
          if (r > 0 && map[r - 1][c] == '#') {
            map[r - 1][c] = '.';
            stack.push_back({r - 1, c});
          }
          if ((r + 1 < n) && map[r + 1][c] == '#') {
            map[r + 1][c] = '.';
            stack.push_back({r + 1, c});
          }
          if (c > 0 && map[r][c - 1] == '#') {
            map[r][c - 1] = '.';
            stack.push_back({r, c -1});
          }
          if ((c + 1 < m) && map[r][c + 1] == '#') {
            map[r][c + 1] = '.';
            stack.push_back({r, c + 1});
          }
        }
      }
    }
  }
  std::cout << island << '\n';

  return 0;
}