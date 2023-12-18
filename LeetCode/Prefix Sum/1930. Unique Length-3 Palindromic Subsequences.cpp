#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<pair<int, int>> lookup(26, pair<int, int>({ 1e9, -1e9 }));

        for (int i = 0; i < s.size(); i++) {
            lookup[s[i] - 'a'].first = min(lookup[s[i] - 'a'].first, i);
            lookup[s[i] - 'a'].second = max(lookup[s[i] - 'a'].second, i);
        }

        cout << lookup << endl;

        for (auto iter : lookup) {
            int left, right;
            tie(left, right) = iter;
            if (left == 1e9) {
                continue;
            }
            // count pattern XYX, where X is the same character at both ends and Y can be any character.
            unordered_set<char> st;
            for (int j = left + 1; j < right; j++) {
                st.insert(s[j]);
            }
            ans += st.size();
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    cout << s.countPalindromicSubsequence("bbcbaba") << endl;
    return 0;
}
