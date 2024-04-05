#include <vector>
#include <iostream>
#include <string>
#include "../prettyprint.h"

using namespace std;

/**
 *      (
        ((
        (((
        ((()
        ((())
        ((()))  <-- 1

        (()
        (()(
        (()()
        (()())  <-- 2

        (())
        (())(
        (())()  <-- 3

        ()
        ()(
        ()((
        ()(()
        ()(())  <-- 4

        ()()
        ()()(
        ()()()  <-- 5
 *
 */

class Solution {
    vector<string> res;
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

        if (close > 0 && close > open) {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s, n, n);
        return res;
    }
};
