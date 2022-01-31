#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }

        // find reverse group
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail) {  // less than k nodes, do nothing
                return head;
            }
            tail = tail->next;
        }

        // reverse group
        ListNode* newHead = reverse(head, tail);

        // old head is now tail, so head->next is the remaining
        // part of reverse group (with/without been reversed)
        head->next = reverseKGroup(tail, k);

        // return new head
        return newHead;
    }

private:
    // reverse [head, tail)
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
