#include <iostream>
#include <memory>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  if (n < 0) {
    return 1;
  }

  auto arr = std::make_unique<int[]>(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  int target = 0;
  std::cin >> target;

  int left = 0;
  int right = n - 1;
  bool found = false;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      found = true;
      break;
    }

    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  std::string result = (found ? "YES" : "NO");
  std::cout << result << '\n';

  return 0;
}