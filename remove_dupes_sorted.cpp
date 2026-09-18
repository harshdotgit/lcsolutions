#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty())
      return 0;
    int k{1};
    for (size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] != nums[k - 1]) {
        nums[k] = nums[i];
        ++k;
      }
    }
    return k;
  }
};

int main() {

  Solution sol{};
  std::vector<int> nums{1, 2, 2, 2, 2, 2, 3, 3, 4, 5};
  std::cout << sol.removeDuplicates(nums) << "\n";

  return EXIT_SUCCESS;
}
