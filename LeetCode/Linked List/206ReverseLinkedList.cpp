#include "../ListNode.h"
#include "../binarytree.h"
#include "../prettyprint.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* node = nullptr;

        ListNode* iter = head;
        while (iter != nullptr) {
            node = iter->next;
            iter->next = prev;

            prev = iter;
            iter = node;
        }

        return prev;
    }
};
