#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int res = 0;
        for (const auto& c : s) {
            // open bracket
            if (c == '(') {
                stack.push(res);
                res = 0;
            }
            // closed bracket
            else {
                int prev = stack.top(); stack.pop();
                res += prev + max(res, 1);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.scoreOfParentheses("(()(()))") << endl;
    return 0;
}

