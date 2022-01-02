#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(begin(nums), end(nums));
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        return (x - 1) * (y - 1);
    }
};
