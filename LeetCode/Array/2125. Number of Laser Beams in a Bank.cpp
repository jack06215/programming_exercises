#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        vector<int> v(bank.size(), 0);
        for (auto s : bank) {
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1') {
                    count++;
                }
            }
            if (count > 0) {
                v.push_back(count);
            }
        }

        for (int i = 1; i < v.size(); i++) {
            int t = v[i] * v[i - 1];
            res += t;
        }

        return res;
    }
};
