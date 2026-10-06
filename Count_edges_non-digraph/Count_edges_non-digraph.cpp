#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  int matrix[103][103];  // с запасом (N <= 100)

  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
      if (matrix[i][j] == 1) {
        count++;
      }
    }
  }
  std::cout << count / 2 << '\n';

  return 0;
}