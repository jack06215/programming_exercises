#include <vector>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) : begin{ 0 }, end{ -1 } {
        data.resize(k);
        size = data.size();
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        end = (end + 1) % size;
        data[end] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        // reset to default, i.e. no element!
        if (begin == end) {
            begin = 0;
            end = -1;
        }
        else {
            begin = (begin + 1) % size;
        }
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