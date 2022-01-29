#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0;
        int right = position.back() - position.front();
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (count(position, mid) >= m) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
private:
    int count(vector<int>& position, int d) {
        int ans = 1;
        int cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
};