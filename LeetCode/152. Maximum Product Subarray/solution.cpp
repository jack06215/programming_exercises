#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq{nums.begin(), nums.end()};
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        return (x - 1) * (y - 1);
    }
};
