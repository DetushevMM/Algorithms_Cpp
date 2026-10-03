#include <iostream>

int main() {
  int n = 0;
  if (!(std::cin >> n) || n <= 0) {
    return 1;
  }
 
  int* stairs = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> stairs[i];
  }

  int* max_sum = new int[n];

  max_sum[0] = stairs[0];

  if (n > 1) {
    int from_zero = max_sum[0] + stairs[1];
    int from_ground = stairs[1];
    max_sum[1] = (from_zero > from_ground) ? from_zero : from_ground;
  }

  for (int i = 2; i < n; ++i) {
    int from_prev = max_sum[i - 1] + stairs[i];
    int from_prev2 = max_sum[i - 2] + stairs[i];
    max_sum[i] = (from_prev > from_prev2) ? from_prev : from_prev2;
  }
  std::cout << max_sum[n - 1] << '\n';

  delete[] stairs;
  delete[] max_sum;

  return 0;
}
