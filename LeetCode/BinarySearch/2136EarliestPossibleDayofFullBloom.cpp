#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include "../codec.h"

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<vector<int>> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = { plantTime[i], growTime[i] };
        }
        // sort by grow time
        sort(begin(time), end(time), [](auto& a, auto& b) { return a[1] > b[1]; });

        for (auto val : time) {
            cout << val[0] << " " << val[1] << endl;
        }

        int left = 1;
        int right = numeric_limits<int>::max();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, time)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool check(int deadline, vector<vector<int>>& time) {
        int days = 0;
        for (int i = 0; i < time.size(); i++) {
            days += time[i][0];
            // if (deadline - growTime) is less than plantTime, it's not doable
            if (days > deadline - time[i][1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> plantTime = stringToIntVector("[1,4,3]");
    vector<int> growTime = stringToIntVector("[2,3,1]");
    cout << Solution().earliestFullBloom(plantTime, growTime) << endl;
    return 0;
}

