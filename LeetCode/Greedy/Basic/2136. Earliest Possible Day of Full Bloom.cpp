#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<vector<int>> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = { plantTime[i], growTime[i] };
        }
        sort(time.begin(), time.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1];});

        int res = 0;
        int days = 0;
        for (int i = 0; i < n; i++) {
            days += time[i][0];
            res = max(res, days + time[i][1]);
        }
        return res;
    }
};