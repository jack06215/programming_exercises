#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count = 0;
        for (char ch: s) {
            if (ch == '(' && count++ > 0) res += ch;
            if (ch == ')' && count-- > 1) res += ch;
        }
        return res;
    }
};
