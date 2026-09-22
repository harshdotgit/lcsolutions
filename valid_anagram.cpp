#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {

    if (s.empty() || t.empty())
      return false;

    if (s.length() != t.length())
      return false;

    std::map<char, int> freq1{}, freq2{};
    for (auto &c : s)
      freq1[c]++;
    for (auto &c : t)
      freq2[c]++;

    if (freq1 == freq2)
      return true;

    return false;
  }
};

int main() {

  Solution sol;
  std::cout << sol.isAnagram("anagram", "ngaram") << "\n";

  return EXIT_SUCCESS;
}
