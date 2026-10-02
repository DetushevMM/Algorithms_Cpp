#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  if (n <= 0) {
    return 0;
  }

  if (n == 1) {
    std::cout << 0;
    return 0;
  }

  int x = 0;
  int y = 1;

  std::cout << x << ' ' << y;

  for (int i = 3; i <= n; ++i) {
    int next = x + y;
    std::cout << ' ' << next;

    x = y;
    y = next;
  }
  std::cout << '\n';
  return 0;
}