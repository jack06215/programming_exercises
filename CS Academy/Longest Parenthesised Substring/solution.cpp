#include <stack>
#include <string>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

int longestParenthesisedSubstring(const string& S) {
    stack<int> stk;
    int res = -1;
    // length = i - lastBad
    int lastBad = -1;
    for (int i = 0; i < S.size(); ++i) {
        // append open bracket
        if (S[i] == '(') {
            // length = i - stk[-1]
            stk.push(i);
        }
        // check if closed bracket can match to a valid open bracket
        else {
            // No open bracket, it's invalid parenthesis sequence
            // So let's move the "start index" forward.
            if (stk.empty()) {
                lastBad = i;
            }
            // There is a match
            else {
                // pair bracket together (i.e. pop the top)
                stk.pop();
                // Get longer sequence from the "start index"
                if (stk.empty()) {
                    res = max(res, i - lastBad);
                }
                // Get longer sequence from the valid sequence
                else {
                    res = max(res, i - stk.top());
                }
            }
        }
    }
    return res;
}

int main() {
    string S;
    cin >> S;
    cout << longestParenthesisedSubstring(S) << "\n";
    return 0;
}