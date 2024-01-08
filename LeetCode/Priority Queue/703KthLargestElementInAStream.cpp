#include <vector>
#include <iostream>
#include <queue>
#include "../prettyprint.h"

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
private:
    struct cmp {
        bool operator() (const int& left, const int& right) {
            return left > right;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    int k;
};
