#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        stack<char> stk;

        for (char c : s) {
            if (c == '(') {
                stk.push(c);
                maxDepth = max(maxDepth, static_cast<int>(stk.size()));
            }
            else if (c == ')') {
                stk.pop();
            }
        }
        return maxDepth;
    }
};
