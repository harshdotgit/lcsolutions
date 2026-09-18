#include <cstdlib>
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    if (x < 10)
      return true;
    long x_cpy{x}, y{0};
    while (x_cpy != 0) {
      y = y * 10 + (x_cpy % 10);
      x_cpy /= 10;
    }
    return (y == x);
  }
};

int main() {

  Solution sol;
  sol.isPalindrome(121);

  return EXIT_SUCCESS;
}
