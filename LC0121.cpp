#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.size() <= 1)
      return 0;
    size_t l{0}, r{1};
    int profit{prices[r] - prices[l]}, max{profit};

    while (r < prices.size() && l <= r) {
      profit = prices[r] - prices[l];
      if (profit > max)
        max = profit;

      std::cout << "l: " << l << "\n" << "r: " << r << "\n";

      if (profit < 0)
        l = r;

      else
        ++r;
    }

    return std::max(0, max);
  }
};

int main() {

  Solution sol;
  std::vector<int> test{1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9};

  std::cout << sol.maxProfit(test) << "\n";

  exit(EXIT_SUCCESS);
}
