#include <queue>
#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

vector<int> nums;
int k;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        struct cmp {
            bool operator()(const int& left, const int& right) {
                return left > right;
            }
        };
        priority_queue<int, vector<int>, cmp> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};

int main(int argc, char const* argv[]) {

    nums = { 3,2,1,5,6,4 };
    k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;
    return 0;
}
