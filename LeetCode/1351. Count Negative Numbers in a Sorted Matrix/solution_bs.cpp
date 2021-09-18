#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (auto const& vec: grid) {
            res += countNegativeInt(vec);
        }
        return res;
    }
private:
    int countNegativeInt(const vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return arr.size() - (right + 1);
    }
};
