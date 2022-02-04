#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> dial = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        queue<string> q;
        vector<string> ans;

        q.push("");
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr.length() == digits.length()) {
                ans.push_back(curr);
            }
            else {
                auto s = dial[digits[curr.length()] - '0'];
                for (auto x : s) {
                    q.push(curr + x);
                }
            }

        }
        return ans;
    }
};