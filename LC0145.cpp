#include <cstddef>
#include <iostream>

class Solution {
public:
  bool isPalindrome(const std::string &s) {
    size_t i = 0, j = s.size();

    while (i < j) {
      if (!std::isalnum(static_cast<unsigned char>(s[i]))) {
        ++i;
      } else if (!std::isalnum(static_cast<unsigned char>(s[j - 1]))) {
        --j;
      } else {
        if (std::tolower(static_cast<unsigned char>(s[i])) !=
            std::tolower(static_cast<unsigned char>(s[j - 1])))
          return false;
        ++i;
        if (i == j)
          return true;
        --j;
      }
    }
    return true;
  }
};
int main() {
  Solution sol;
  std::cout << sol.isPalindrome("A man, a plan, a canal: Panama");
}
