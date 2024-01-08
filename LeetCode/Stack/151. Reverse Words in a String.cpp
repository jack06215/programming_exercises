#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string res;
        for (int i = 0; i < s.size(); i++) {
            string word;
            // skip white spaces
            if (s[i] == ' ') {
                continue;
            }

            // store continuous letters into word
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            stk.push(word);
        }

        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
            if (!stk.empty()) {
                res += " ";
            }
        }
        return res;
    }
};

