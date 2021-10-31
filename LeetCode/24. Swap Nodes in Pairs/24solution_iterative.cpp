#include "../ListNode.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
 
    ListNode temp;
    temp.next = head;
    head = &temp;
 
    while (head && head->next && head->next->next) {
      auto n1 = head->next;
      auto n2 = n1->next;
 
      n1->next = n2->next;
      n2->next = n1;
 
      head->next = n2;
      head = n1;
    }
    return temp.next;
  }
};
