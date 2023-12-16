#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (auto c : num) {
            while (!res.empty() && res.back() > c && k > 0) {
                res.pop_back();
                k--;
            }

            if (!res.empty() || c != '0') {
                res.push_back(c);
            }
        }

        while (k > 0 && !res.empty()) {
            k--;
            res.pop_back();
        }

        return res.empty() ? "0" : res;
    }
};
