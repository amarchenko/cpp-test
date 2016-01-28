// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    ListNode* curr = result;
    
    bool carry = false;
    while (l1 || l2) {
      if (l1) curr->val += l1->val;
      if (l2) curr->val += l2->val;

      bool carry = curr->val / 10;
      if (carry) { 
          curr->val -= 10;
      }

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
      
      if (l1 || l2 || carry) curr->next = new ListNode(0);
      if (carry) {
        curr = curr->next;
        curr->val = 1;
        carry = false;
      }
    }

    return result;
  }
};

int main() {
  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(8);
  l1->next->next = nullptr;

  ListNode* l2 = new ListNode(0);
  l2->next = nullptr;

  Solution s;
  ListNode* r = s.addTwoNumbers(l1, l2);

  while (r) {
    std::cout << r->val << " ";
  }
  std::cout << std::endl;
  return 0;
}