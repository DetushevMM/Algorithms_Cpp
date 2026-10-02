#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  const int max_value = 10;

  int count[max_value + 1]{0};

  for (int i = 0; i < n; ++i) {
    int num = 0;
    std::cin >> num;
    count[num]++;
  }

  for (int i = 1; i <= max_value; ++i) {
    for (int j = 0; j < count[i]; ++j) {
      std::cout << i << " ";
    }
  }
  std::cout << '\n';
  return 0;
}