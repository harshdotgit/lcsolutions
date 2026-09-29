#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::map<std::vector<int>, std::vector<std::string>> charMap;
    for (auto &s : strs) {
      std::vector<int> freqCount(26, 0);
      for (char ch : s) {
        freqCount[ch - 'a']++;
      }
      charMap[freqCount].push_back(s);
    }

    std::vector<std::vector<std::string>> groups;

    for (auto keyVal : charMap)
      groups.push_back(keyVal.second);
    return groups;
  }
};

void vecPrint(std::vector<std::vector<std::string>> vec) {
  for (auto &v : vec) {
    for (auto &s : v)
      std::cout << s << ", ";
    std::cout << "\n";
  }
}

int main() {
  Solution sol;
  std::vector<std::string> test{"eat", "tea", "tan", "ate", "nat", "bat"};
  auto vec{sol.groupAnagrams(test)};
  vecPrint(vec);
}
