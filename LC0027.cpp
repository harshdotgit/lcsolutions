#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int i{0}, n{static_cast<int>(nums.size())};
    while (i < n) {
      if (nums[i] == val) {
        nums[i] = nums[--n];
      } else {
        ++i;
      }
    }
    return n;
  }
};

void printVec(std::vector<int> vec) {
  for (auto &v : vec)
    std::cout << v << " ";
}

int main() {
  Solution sol;
  std::vector<int> test{1, 2, 3, 4, 5, 6, 4, 4, 4, 5, 6, 7, 5, 4};
  printVec(test);
  std::cout << "\n" << sol.removeElement(test, 4) << "\n";
  printVec(test);
}
