#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  bool isValid(std::string s) {
    std::vector<char> stack;
    for (char c : s) {
      if (!stack.empty() && ((stack.back() == '[' && c == ']') ||
                             (stack.back() == '{' && c == '}') ||
                             (stack.back() == '(' && c == ')'))) {
        stack.pop_back();
      } else {
        stack.push_back(c);
      }
    }
    return stack.empty();
  }
};

int main() {
  Solution sol{};
  std::cout << sol.isValid("{[])") << "\n";
  return EXIT_SUCCESS;
}
