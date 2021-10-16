#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "../prettyprint.h"

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k): begin{0}, end{-1} {
        data.resize(k);
        size = data.size();
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        end = (end + 1) % size;
        data[end] = value;
        cout << data << " head: " << begin << " tail: " << end << endl;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        // reset to default, i.e. no element!
        if (begin == end) {
            begin = 0;
            end = -1;
        }
        else {
            begin = (begin + 1) % size;
        }
        cout << data << " head: " << begin << " tail: " << end << endl;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : data[begin];
    }
    
    int Rear() {
        return isEmpty() ? -1 : data[end];
    }
    
    bool isEmpty() {
        return end == -1;
    }
    
    bool isFull() {
        return !isEmpty() && (end + 1) % size == begin;
    }
private:
    vector<int> data;
    int size;
    int begin;
    int end;
};

int main(int argc, char const *argv[]) {
    MyCircularQueue queue(4);
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.deQueue();
    queue.enQueue(5);
    return 0;
}


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */