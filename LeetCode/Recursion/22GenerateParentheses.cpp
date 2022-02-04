#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s, n, n);
        return res;
    }
private:
    void generate(string& s, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }

        if (open > 0) {
            s.push_back('(');
            generate(s, open - 1, close);
            s.pop_back();
        }

        if (close > 0) {
            if (close > open) {
                s.push_back(')');
                generate(s, open, close - 1);
                s.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generate("", n, n);
        return ans;
    }
    void generate(string s, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            generate(s + "(", open - 1, close);
        }
        if (open < close) {
            generate(s + ")", open, close - 1);
        }
    }
};