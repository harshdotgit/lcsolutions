#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  int romanToInt(std::string s) {
    int total{0};
    std::map<char, int> numMap{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}};
    // subtraction case
    for (size_t i{0}; i < s.length(); ++i) {
      total += numMap[s[i]];
      if (i != 0) {
        if (((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I') ||
            ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X') ||
            ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C'))
          total -= 2 * numMap[s[i - 1]];
      }
      std::cout << total << "\n";
    }

    return total;
  }
};

int main() {

  Solution sol;
  std::cout << sol.romanToInt("MCMXCIV") << "\n";

  return EXIT_SUCCESS;
}
