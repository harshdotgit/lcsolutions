#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int reversed{0};

    while (x != 0) {

      if (reversed > INT_MAX / 10 ||
          reversed < INT_MIN / 10) // log2(reversed*10) > 31)
        return 0;

      reversed = (reversed * 10) + (x % 10);
      x /= 10;
    }

    return reversed;
  }
};

int main() {
  Solution sol;
  std::cout << sol.reverse(1534236469) << "\n";
}
