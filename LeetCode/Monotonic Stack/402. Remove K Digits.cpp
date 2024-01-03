#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (auto c : num) {
            // check if the current digit is smaller than last digit in the `res`
            // and if there are still `k` characters to be removed
            while (!res.empty() && res.back() > c && k > 0) {
                res.pop_back();
                k--;
            }

            // only non-leading zeros are not added to the result
            if (!res.empty() || c != '0') {
                res.push_back(c);
            }
        }
        // handles the scenario where there are still digits to be removed after the first loop
        while (k > 0 && !res.empty()) {
            k--;
            res.pop_back();
        }

        return res.empty() ? "0" : res;
    }
};
