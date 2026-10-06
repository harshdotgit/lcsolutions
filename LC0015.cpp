#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> triplets{};
    std::sort(nums.begin(), nums.end());

    int l, r, sum;

    for (size_t i{0}; i < nums.size(); ++i) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        r = nums.size() - 1;
        l = i + 1;

        while (l < r) {
          sum = nums[i] + nums[l] + nums[r];
          if (sum > 0)
            r--;
          else if (sum < 0)
            l++;
          else {
            triplets.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
            l++;
            while (l < r && nums[l] == nums[l - 1])
              l++;
          }
        }
      }
    }

    return triplets;
  }
};

void vecPrint(std::vector<std::vector<int>> vec) {
  for (auto &v : vec) {
    for (auto &s : v)
      std::cout << s << ", ";
    std::cout << "\n";
  }
}

int main() {
  Solution sol;
  std::vector<int> test{0, 0, 0};
  std::vector<std::vector<int>> testVec{sol.threeSum(test)};
  vecPrint(testVec);
}
