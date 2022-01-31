#include "../ListNode.h"


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // find length
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // reset
        tail->next = head;
        
        const int t = len - k % len;
        for (int i = 0; i < t; ++i) {
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};
