#include <queue>
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }
        if (q.empty()) {
            return nullptr;
        }

        ListNode* result = q.top(); q.pop();
        if (result->next) {
            q.push(result->next);
        }
        ListNode* tail = result;
        while (!q.empty()) {
            tail->next = q.top(); q.pop();
            tail = tail->next;
            if (tail->next) {
                q.push(tail->next);
            }
        }
        return result;
    }
};
