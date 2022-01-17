#include "../ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* nextHead = head->next;
        head->next = swapPairs(nextHead->next);
        nextHead->next = head;
        return nextHead;
    }
};
