#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int res = 0;
        for (auto c : s) {
            if (c == '(') {
                stack.push(res);
                res = 0;
            }
            else {
                int prev = stack.top();
                stack.pop();
                res += prev + max(res, 1);
            }
        }
        return res;
    }
};
