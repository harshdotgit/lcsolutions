
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::map<char, int> seen;
    int max{0};
    size_t left{0};

    for (size_t i{0}; i < s.length(); ++i) {
      char temp = s[i];

      while (seen[temp]) {
        --seen[s[left]];
        ++left;
      }

      ++seen[temp];
      max = std::max(max, static_cast<int>(i - left + 1));
    }

    return max;
  }
};

int main() {
  Solution sol;
  std::cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n";
}
