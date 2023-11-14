#include <vector>
#include <unordered_map>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         int ans = 0;
//         unordered_map<int, int> mp;
//         for (int& t : time) {
//             ans += (mp[(60 - t % 60) % 60]);
//             mp[t % 60]++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        // [ mod_time, count ]
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            cout << mp << endl;
            // 0, 1, 2, ..., 59, 60, 61, 62
            // 0, 1, 2, ..., 59,  0,  1, 2
            int m_time = time[i] % 60;

            int bin = 60 - m_time;
            if (mp[bin] > 0) {
                ans += mp[bin];
            }

            if (m_time == 0) {
                mp[60]++;
                continue;
            }
            mp[m_time]++;
        }
        cout << mp << endl;
        return ans;
    }
};


int main() {
    vector<int> time = stringToIntVector("[30,20,150,100,40]");
    cout << Solution().numPairsDivisibleBy60(time) << endl;
    return 0;
}
