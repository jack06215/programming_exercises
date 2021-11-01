#include <iostream>
#include <algorithm>
#include "../ListNode.h"

using namespace std;

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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