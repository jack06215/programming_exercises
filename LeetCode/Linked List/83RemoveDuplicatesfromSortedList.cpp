#include "../ListNode.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* iter = head;
        while (iter->next != nullptr) {
            if (iter->val == iter->next->val) {
                iter->next = iter->next->next;
            }
            else {
                iter = iter->next;
            }
        }
        return head;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}

