#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) {
            return false;
        }
        stack<char> stk;
        for (char const& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            }
            else {
                if (
                    stk.empty() ||
                    stk.top() == '(' && ch != ')' ||
                    stk.top() == '[' && ch != ']' ||
                    stk.top() == '{' && ch != '}'
                    ) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
