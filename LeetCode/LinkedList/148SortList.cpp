#include "../prettyprint.h"
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

    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (left && right) {
            if (left->val > right->val) {
                swap(left, right);
            }
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        tail->next = left ? left : right;
        return dummy.next;
    }
};