#include "../ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        this->remove(dummy, n);
        return dummy->next;
    }
private: 
    int remove(ListNode* node, int n) {
        if (!node) {
            return 1;
        }
        int depth = this->remove(node->next, n);
        if (depth == n + 1) {
            node->next = node->next->next;
        }
        return depth + 1;
    }
};
