#include <iostream>
#include <vector>
#include <algorithm>
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mergeList(sortList(head), sortList(mid));
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
          if (l1->val > l2->val) {
              swap(l1, l2);
          }
          
          tail->next = l1;
          l1 = l1->next;
          tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;    
        return dummy.next;
    }
};
