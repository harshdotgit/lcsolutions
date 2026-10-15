#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    if (s.length() < t.length())
      return "";

    std::unordered_map<char, int> s_map, t_map;
    for (char c : t)
      t_map[c]++;

    size_t have{0}, need{t.length()};
    size_t best_l{0}, best_len{SIZE_MAX};
    size_t l{0};

    for (size_t r = 0; r < s.length(); ++r) {
      char c = s[r];
      if (t_map.count(c) && ++s_map[c] <= t_map[c])
        ++have;

      while (have == need) {
        if (r - l + 1 < best_len) {
          best_len = r - l + 1;
          best_l = l;
        }
        char lc = s[l];
        if (t_map.count(lc) && --s_map[lc] < t_map[lc])
          --have;
        ++l;
      }
    }

    return best_len == SIZE_MAX ? "" : s.substr(best_l, best_len);
  }
};

int main() {
  Solution sol;
  std::cout << sol.minWindow("abddddsxbgsdjhjhcbahdd", "cbd") << "\n";
}
