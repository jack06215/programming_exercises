#include <vector>
#include <iostream>
#include <limits>
#include "prettyprint.h"

using namespace std;

class MyQueue {
public:
    MyQueue(int size): head(0), tail(-1), size(size) {
        queue.resize(size);
    }
    void push(int val) {
        if (tail + 1 < size) {
            queue[++tail] = val;
            cout << queue << "\thead: " << head << "\ttail: " << tail << endl;
        }
        else {
            cout << "ERR!! cannot push anymore!!" << endl;
        }
        return;
    }
    
    void pop() {
        if (head < tail) {
            // queue[head] = numeric_limits<int>::min();
            head++;
            cout << queue << "\thead: " << head << "\ttail: " << tail << endl;
        }
        else {
            cout << "ERR!! cannot pop anymore!!" << endl;
        }
        return;
    }

    int peek() const {
        return queue[head];
    }
private:
    vector<int> queue;
    int size;
    int head;
    int tail;
};

int main(int argc, char const *argv[]) {
    MyQueue queue(4);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    // queue.peek();
    // queue.pop();
    // queue.peek();
    // queue.pop();
    // queue.pop();
    // queue.pop();
    // queue.pop();
    return 0;
}
