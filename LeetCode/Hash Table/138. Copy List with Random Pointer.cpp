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
    unordered_map<Node*, Node*> node_lookup;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* curr = head;
        while (curr) {
            node_lookup[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            node_lookup[curr]->next = node_lookup[curr->next];
            node_lookup[curr]->random = node_lookup[curr->random];
            curr = curr->next;
        }

        return node_lookup[head];
    }
};
