#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry{0};
    ListNode *result{new ListNode{0}};
    ListNode *temp = result;
    int a{0}, b{0};

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      a = 0, b = 0;
      if (l1 != nullptr) {
        a = l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        b = l2->val;
        l2 = l2->next;
      }

      temp->val = (a + b + carry) % 10;
      carry = (a + b + carry) / 10;
      if (l1 != nullptr || l2 != nullptr || carry != 0) {
        temp->next = new ListNode(0);
        temp = temp->next;
      }
    }

    return result;
  }
};

void printSol(ListNode *result) {
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
}

int main() {
  Solution sol;

  ListNode *t1l1 =
      new ListNode(6, new ListNode(5, new ListNode(2, new ListNode(5))));
  ListNode *t1l2 = new ListNode(4, new ListNode(2, new ListNode(1)));
  std::cout << "Test 1 (expected: 0 8 3): ";
  printSol(sol.addTwoNumbers(t1l1, t1l2));
  std::cout << "\n";

  ListNode *t2l1 = new ListNode(1, new ListNode(0, new ListNode(1)));
  ListNode *t2l2 = new ListNode(1, new ListNode(4, new ListNode(2)));
  std::cout << "Test 2 (expected: 2 4 3): ";
  printSol(sol.addTwoNumbers(t2l1, t2l2));
  std::cout << "\n";

  // Test 3: 342 + 465 = 807
  ListNode *t3l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *t3l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  std::cout << "Test 3 (expected: 7 0 8): ";
  printSol(sol.addTwoNumbers(t3l1, t3l2));
  std::cout << "\n";

  // Test 4: 0 + 0 = 0
  ListNode *t4l1 = new ListNode(0);
  ListNode *t4l2 = new ListNode(0);
  std::cout << "Test 4 (expected: 0): ";
  printSol(sol.addTwoNumbers(t4l1, t4l2));
  std::cout << "\n";

  // Test 5: 9999999 + 9999 = 10009998
  ListNode *t5l1 = new ListNode(
      9, new ListNode(
             9, new ListNode(
                    9, new ListNode(
                           9, new ListNode(
                                  9, new ListNode(9, new ListNode(9)))))));
  ListNode *t5l2 =
      new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
  std::cout << "Test 5 (expected: 8 9 9 9 0 0 0 1): ";
  printSol(sol.addTwoNumbers(t5l1, t5l2));
  std::cout << "\n";
}
