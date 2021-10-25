#include <vector>
#include <deque>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class MonotonicQueue {
public:
    void push(int val) {
        // pop all elements smaller than val
        while (!_data.empty() && val > _data.back()) {
            _data.pop_back();
        }
        _data.push_back(val);
    }

    void pop() {
        _data.pop_front();
    }

    int max() const {
        return _data.front();
    }
private:
    deque<int> _data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> res;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            q.push(nums[i]);
            if (i - k + 1 >= 0) {
                res.push_back(q.max());
                if (nums[i - k + 1] == q.max()) {
                    q.pop();
                }
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums;
    int k;

    nums = { 1,3,-1,-3,5,3,6,7 }, k = 3;
    cout << s.maxSlidingWindow(nums, k) << endl;
    return 0;
}

