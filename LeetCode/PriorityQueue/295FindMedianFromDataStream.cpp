#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "../prettyprint.h"

using namespace std;

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        // by default we consider the element on the left side i.e. max heap
        if (maxpq.empty() || maxpq.top() > num) {
            maxpq.push(num);
        }
        else {
            minpq.push(num);
        }
        // if right side is greater (min heap) then put 1 element of right side to left side (max heap) 
        if (maxpq.size() + 1 < minpq.size()) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
        // if left side is greater (max heap) then put 1 element of left side to right side (min heap)
        else if (minpq.size() + 1 < maxpq.size()) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
    }

    double findMedian() {
        if (maxpq.size() == minpq.size()) {
            return (maxpq.top() + minpq.top()) * 0.5;
        }
        return maxpq.size() > minpq.size() ? maxpq.top() : minpq.top();
    }
private:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
};
