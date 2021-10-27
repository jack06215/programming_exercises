#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert_front(int val) {
        Node* tmp = new Node();
        tmp->val = val;
        tmp->next = this->head;
        this->head = tmp;
        head = tmp;
    }

    void insert_back(int val) {
        Node* tmp = new Node();
        if (head == nullptr) {
            this->insert_front(val);
            return;
        }
        Node* tail = head;
        tmp->val = val;
        tmp->next = nullptr;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = tmp;
    }

    void insert_at(int val, int index) {
        Node* iter = head;
        Node* tmp = new Node();
        tmp->val = val;
        while (--index) {
            iter = iter->next;
        }
        tmp->next = iter->next;
        iter->next = tmp;
    }

    void print() {
        Node* curr = new Node();
        curr = head;
        while (curr != nullptr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

    void delete_front() {
        Node* newHead = head->next;
        delete head;
        head = newHead;
    }

    void delete_back() {
        Node* iter = head;
        Node* prev = head;
        while (iter->next != nullptr) {
            prev = iter->next;
            iter = prev->next;
        }
        prev->next = nullptr;
        delete iter;
    }

    void delete_at(int index) {
        Node* iter = head;
        while (--index) {
            iter = iter->next;
        }
        Node* garbage = iter->next;
        iter->next = iter->next->next;
        delete garbage;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }
private:
    Node* head;
};

int main(int argc, char const* argv[]) {
    LinkedList ll;
    ll.insert_back(1);
    ll.insert_back(2);
    ll.insert_back(3);
    ll.insert_back(4);
    ll.insert_back(5);
    ll.insert_at(9, 2);
    ll.delete_at(2);
    ll.delete_back();
    ll.delete_front();
    ll.reverse();
    ll.print();
    return 0;
}
