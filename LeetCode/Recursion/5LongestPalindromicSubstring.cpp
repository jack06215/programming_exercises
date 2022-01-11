#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> memo(1001, vector<int>(1001, -1));
        vector<int> answer = { 0, 0, 1 };
        helper(0, s.size() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
    }

    bool helper(int left, int right, string& s, vector<vector<int>>& memo, vector<int>& answer) {
        // Check if [L ... R] is already calculated before
        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        // Base case, every single letter or empty string is also a palindrome
        if (left >= right) {
            return true;
        }

        // Possible palindrome beginning
        bool found = false;
        if (s[left] == s[right]) {
            found = true && helper(left + 1, right - 1, s, memo, answer);
        }

        // Try other possibilities
        helper(left + 1, right, s, memo, answer);
        helper(left, right - 1, s, memo, answer);

        // Update longest palindrome position and width
        if (found && (right - left + 1) > answer[2]) {
            answer = { left, right, (right - left + 1) };
        }
        // Memoization
        memo[left][right] = found;
        return found;
    }
};