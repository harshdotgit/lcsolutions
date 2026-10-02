#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::set<int> uniqueNums{};
    for (auto &n : nums)
      uniqueNums.insert(n);

    int longest = 0, len = 0;
    for (auto &n : uniqueNums) {
      if (uniqueNums.find(n - 1) == uniqueNums.end()) {
        len = 0;
        while (uniqueNums.find(n + len) != uniqueNums.end())
          ++len;
        longest = std::max(len, longest);
      }
    }
    return longest;
  }
};

int main() {
  Solution sol;
  std::vector<int> test{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  std::cout << sol.longestConsecutive(test) << "\n";
}
