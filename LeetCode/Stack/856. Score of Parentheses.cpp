#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for (auto c : s) {
            if (c == '(') {
                stk.push(res);
                res = 0;
            }
            else {
                int prev_score = stk.top();
                stk.pop();
                res += prev_score + max(res, 1);
            }
        }
        return res;
    }
};

int main(int argc, const char* argv[]) {
    cout << Solution().scoreOfParentheses("(())") << endl;
    return 0;
}