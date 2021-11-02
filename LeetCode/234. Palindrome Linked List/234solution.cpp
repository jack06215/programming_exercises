#include "../ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *XOR(ListNode *a, ListNode *b) {
        return (ListNode *) ((intptr_t) (a) ^ (intptr_t) (b));
    }
    bool isPalindrome(ListNode *head) {
        /* turn it into a xor linked list */
        ListNode *prev = NULL;
        int n = 0;
        for (ListNode *curr = head; curr != NULL; n++) {
            ListNode *next = curr->next;
            curr->next = XOR(prev, next);
            prev = curr;
            curr = next;
        }
        /* check the palindrome */
        ListNode *left = head; ListNode *left_prev = NULL;
        ListNode *right = prev; ListNode *right_prev = NULL;
        int i = 0;
        for (; i < n / 2; ++i) {
            if (left->val != right->val) break;
            left_prev = XOR(left_prev,left->next);
            swap(left_prev, left);
            right_prev = XOR(right_prev,right->next);
            swap(right_prev, right);
        }
        /* restore the singly linked list */
        prev = NULL;
        for (ListNode* curr = head; curr != NULL; curr = curr->next) {
            curr->next = XOR(prev, curr->next);
            prev = curr;
        }
        return i >= n / 2;
    }
};