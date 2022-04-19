#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include "../../prettyprint.h"

using namespace std;

/*
    Iterate through the string and
    - if we get s[i] == "(" then store it’s index ink 
    - if we get s[i] == ")" and stack is empty means this closing parenthesis will not be part of any valid substring
    - if the stack is not empty then we store length of current substring in
        dp[i] = dp[stack[-1] - 1] + dp[i - 1] + 1
    - for every s[i] = "(" we store dp[i] = 0
    - for every s[i] = ")" where there is no pair for this s[i] means stack is empty we store dp[i] = 0 .

    Example:
    string- )  (  (  )  )  (  )  (  )
    index - 0  1  2  3  4  5  6  7  8

    - When i = 3 and i = 2 will form 1 valid pair so we store
        dp[3]= dp[2] + dp[1] + 1
      So while i = 3 is making pair with i = 2 , we are checking dp at i = 1 because
      we want to get longest valid substring so if there is any substring till i = 1 which is also valid we will add that also.

    - Then we move to index 4 and stack is not empty so we will check for dp[stack[-1] – 1] e 
      stack[-1] = 1 because i = 4 is making pair with i = 1 so top of stack will be 1.
        dp[4] = dp[3] + dp[0] + 1

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<int> dp(s.size() + 1, 0);
        int res = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '(') {
                stk.push(i - 1);
                dp[i] = 0;
            }
            else if (s[i - 1] == ')') {
                if (stk.empty()) {
                    dp[i] = 0;
                }
                if (!stk.empty() && s[stk.top()] == '(') {
                    dp[i] = dp[i - 1] + dp[stk.top()] + 1;
                    stk.pop();
                }
            }
            res = max(res, dp[i]);
        }
        return 2 * res;
    }
};

int main(int argc, char const* argv[]) {
    string s = ")(())()()";
    cout << Solution().longestValidParentheses(s) << endl;
    return 0;
}
