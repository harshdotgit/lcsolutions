#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> freqCount;
    for (int n : nums)
      freqCount[n]++;

    std::vector<std::vector<int>> bucket(nums.size() + 1);
    for (const auto &keyVal : freqCount)
      bucket[keyVal.second].push_back(keyVal.first);

    std::vector<int> result;
    for (size_t f = bucket.size();
         f-- > 0 && result.size() < static_cast<size_t>(k);) {
      for (int num : bucket[f]) {
        result.push_back(num);
        if (result.size() == static_cast<size_t>(k))
          break;
      }
    }
    return result;
  }
};

void printVec(const std::vector<int> &vec) {
  for (int i : vec)
    std::cout << i << "\n";
}

int main() {
  Solution sol;
  std::vector<int> test{1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
  printVec(sol.topKFrequent(test, 2));
}
