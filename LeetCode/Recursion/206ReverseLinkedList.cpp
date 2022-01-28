#include "../ListNode.h"
#include "../binarytree.h"
#include "../prettyprint.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        // new head
        auto node = reverseList(head->next);
        // reverse link prev
        head->next->next = head;

        // break link
        head->next = nullptr;

        return node;
    }
};
