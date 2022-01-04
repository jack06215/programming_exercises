#include <vector>
#include <iostream>
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        }
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        // store LSD
        ListNode* newHead = new ListNode(sum % 10);

        // carry bit
        sum /= 10;

        // add carry
        ListNode* next1 = l1 ? l1->next : nullptr;
        if (next1) {
            next1->val += sum;
        }
        // no carry, create new node to store value
        else if (sum) {
            next1 = new ListNode(sum);
        }
        // resursive
        ListNode* next2 = l2 ? l2->next : nullptr;
        newHead->next = addTwoNumbers(next1, next2);
        return newHead;
    }
};