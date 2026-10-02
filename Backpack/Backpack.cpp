#include <iostream>

int main() {
  int w = 0;
  int n = 0;

  std::cin >> w >> n;

  int weights[300];
  for (int i = 0; i < n; ++i) {
    std::cin >> weights[i];
  }

  int dp[10001]{0};

  for (int i = 0; i < n; ++i) {
    for (int j = w; j >= weights[i]; --j) {
      int take = dp[j - weights[i]] + weights[i];
      if (take > dp[j]) {
        dp[j] = take;
      }
    }
  }
  std::cout << dp[w] << '\n';
  return 0;
}