#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    void print() {
        auto curr = next;
        while (curr != nullptr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << endl;
    }
};
