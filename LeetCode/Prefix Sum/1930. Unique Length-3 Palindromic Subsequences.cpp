#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        vector<pair<int, int>> m(26, pair<int, int>({ 1e9, -1e9 }));

        for (int i = 0; i < n; i++) {
            m[s[i] - 'a'].first = min(m[s[i] - 'a'].first, i);
            m[s[i] - 'a'].second = max(m[s[i] - 'a'].second, i);
        }

        cout << m << endl;

        for (auto i : m) {
            int l = i.first;
            int r = i.second;
            if (l == 1e9) {
                continue;
            }
            unordered_set<char> st;
            for (int j = l + 1; j < r; j++) {
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
