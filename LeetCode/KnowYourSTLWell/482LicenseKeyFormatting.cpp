#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        int k = K;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                if (k == 0) {
                    result.push_back('-');
                    k = K;
                }
                result.push_back(toupper(S[i]));
                k--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
