#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int st = 0;
        string ans;
        for (auto a : s) {
            if (a == '(') {
                if (st > 0) {
                    ans += '(';
                }
                st++;
            }
            else {
                if (st > 1) {
                    ans += ')';
                }
                st--;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string ans;
        for (auto a : s) {
            if (a == '(') {
                if (stk.size() > 0) {
                    ans += '(';
                }
                stk.push('(');
            }
            else {
                if (stk.size() > 1) {
                    ans += ')';
                }
                stk.pop();
            }
        }
        return ans;
    }
};