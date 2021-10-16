#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() < 2) return false;
        stack<char> res;
        for (const char& ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                res.push(ch);
            } 
            else {
                if (res.empty() ||
                    res.top() == '(' && ch != ')' || res.top() == '[' && ch != ']' || res.top() == '{' && ch != '}') {
                    return false;
                }
                res.pop();
            }
        }
        return res.empty();
    }
};
