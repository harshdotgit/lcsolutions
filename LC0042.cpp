#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {

    int n = static_cast<int>(height.size());
    if (n <= 2)
      return 0;

    std::vector<int> maxL(n), maxR(n);

    maxL[0] = height[0];
    for (int i{1}; i < n; ++i)
      maxL[i] = std::max(maxL[i - 1], height[i]);

    maxR[n - 1] = height[n - 1];
    for (int j{n - 2}; j >= 0; --j)
      maxR[j] = std::max(maxR[j + 1], height[j]);

    int water{0};
    for (int i{0}; i < n; ++i)
      water += std::min(maxL[i], maxR[i]) - height[i];

    return water;
  }
};

int main() {

  Solution sol;
  std::vector<int> test{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << sol.trap(test) << "\n";

  exit(EXIT_SUCCESS);
}
