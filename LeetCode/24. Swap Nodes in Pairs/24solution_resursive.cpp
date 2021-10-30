#include "../ListNode.h"


/*
    [1 -> 2 -> 3 -> 4]
    
    1 -> swapPairs([3 -> 4])
    2 -> 1

    [3, 4]
    swapPairs([3 -> 4]) == 3 -> swapPairs(NULL) == 3 -> null
    4 -> 3 -> null
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *nextHead = head->next;        
        head->next = swapPairs(nextHead->next);
        nextHead->next = head;
        return nextHead;
    }
};
