#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::map<int, std::vector<int>> idxMap{};
    for (int i{0}; i < nums.size(); ++i) {
      idxMap[nums[i]].push_back(i);
    }
    for (auto pair : idxMap) {
      if ((target - pair.first == pair.first) && (pair.second.size() >= 2)) {
        return std::vector<int>{pair.second[0], pair.second[1]};
      } else if (idxMap.count(target - pair.first))
        return std::vector<int>{pair.second[0], idxMap[target - pair.first][0]};
    }

    return std::vector<int>{-1, -1};
  }
};

int main() {
  Solution sol{};
  std::vector<int> test{3, 3};
  std::vector<int> testResult{sol.twoSum(test, 6)};
  std::cout << testResult[0] << ", " << testResult[1] << "\n";
}
