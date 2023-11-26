#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head, Node* result = nullptr) {
        if (!head) {
            return head;
        }
        auto result = new Node(head->val);
        map[head] = result;
        result->next = copyRandomList(head->next, result->next);
        result->random = map[head->random];
        return result;
    }
};

class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        Node* iter = head;

        Node* newHead = nullptr;
        Node* newTail = nullptr;
        while (iter != nullptr) {
            if (newHead == nullptr) {
                newHead = new Node(iter->val);
                newTail = newHead;
            }
            else {
                newTail->next = new Node(iter->val);
                newTail = newTail->next;
            }
            map[iter] = newTail;
            iter = iter->next;
        }


        iter = newHead;
        while (iter != nullptr) {
            iter->random = map[head->random];
            head = head->next;
            iter = iter->next;
        }
        return newHead;

    }
};
