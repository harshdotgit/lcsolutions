#include <climits>
#include <iostream>
#include <string>

class Solution {
public:
  int myAtoi(std::string s) {
    int i{0};
    uint8_t p{0};
    size_t idx{0};
    for (; s[idx] == ' '; ++idx)
      ;

    if (s[idx] == '-') {
      p = 1;
      ++idx;
    } else if (s[idx] == '+') {
      ++idx;
    }

    for (; idx < s.size(); ++idx) {
      if (s[idx] - '0' < 0 || s[idx] - '0' > 9)
        break;
      else {
        if (i > INT_MAX / 10 ||
            (i == INT_MAX / 10 && s[idx] - '0' > INT_MAX % 10)) {
          return p ? INT_MIN : INT_MAX;
        }
        i = i * 10 + static_cast<int>(s[idx] - '0');
      }
    }
    return pow(-1, p) * i;
  }
};

int main() {
  Solution sol;
  std::cout << sol.myAtoi("-42") << "\n";
}
