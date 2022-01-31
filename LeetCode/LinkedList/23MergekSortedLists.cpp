#include "../ListNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        if (pq.empty()) {
            return nullptr;
        }

        ListNode* newHead = pq.top();
        pq.pop();
        if (newHead->next) {
            pq.push(newHead->next);
        }
        ListNode* tail = newHead;
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next) {
                pq.push(tail->next);
            }
        }
        return newHead;
    }
};