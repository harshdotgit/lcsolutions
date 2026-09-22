#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::map<int, int> freq{};
    for (auto &i : nums)
      freq[i]++;

    for (auto keyVal : freq)
      if (keyVal.second > 1)
        return true;

    return false;
  }
};

int main() {
  Solution sol;
  std::vector<int> test{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  std::cout << sol.containsDuplicate(test) << "\n";
}
