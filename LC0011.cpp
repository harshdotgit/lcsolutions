#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int max{0}, area;

    size_t l{0}, r{height.size() - 1};

    while (l < r) {
      area = (r - l) * std::min(height[l], height[r]);
      if (area > max)
        max = area;
      if (height[r] < height[l])
        --r;
      else
        ++l;
    }

    return max;
  }
};

int main() {

  Solution sol;
  std::vector<int> test{1, 1};

  std::cout << sol.maxArea(test) << "\n";

  exit(EXIT_SUCCESS);
}
