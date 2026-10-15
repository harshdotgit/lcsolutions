#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    if (s2.length() < s1.length())
      return false;

    std::map<char, int> s1_chars;
    size_t checked{0};

    for (auto c : s1)
      s1_chars[c]++;

    size_t window{s1.size()};
    size_t l{0}, r{s1.size()};

    while (r <= s2.length()) {
      std::map<char, int> s2_chars;

      for (size_t i{l}; i < r; ++i)
        s2_chars[s2[i]]++;

      checked = 0;

      for (auto keyVal : s1_chars) {
        if (keyVal.second == s2_chars[keyVal.first])
          ++checked;
      }

      if (checked == s1_chars.size())
        return true;

      ++l;
      ++r;
    }

    return false;
  }
};

int main() {
  Solution sol;
  std::string test_s1{"abcdxabcde"};
  std::string test_s2{"abcdeabcdx"};

  std::cout << sol.checkInclusion(test_s1, test_s2) << "\n";
}
