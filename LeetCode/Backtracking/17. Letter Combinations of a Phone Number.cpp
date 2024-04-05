#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include "../prettyprint.h"

using namespace std;

/*
    Explanation with sample input "123"

    Initial state:

    result = {""}
    Stage 1 for number "1":

    result has {""}
    candiate is "abc"
    generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
    tmp = {"a", "b","c"}
    swap result and tmp (swap does not take memory copy)
    Now result has {"a", "b", "c"}
    Stage 2 for number "2":

    result has {"a", "b", "c"}
    candidate is "def"
    generate nine strings and put into tmp,
    "a" + "d", "a"+"e", "a"+"f",
    "b" + "d", "b"+"e", "b"+"f",
    "c" + "d", "c"+"e", "c"+"f"
    so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
    swap result and tmp
    Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
    Stage 3 for number "3":

    result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
    candidate is "ghi"
    generate 27 strings and put into tmp,
    add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
    add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
    add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
    so, tmp has
    {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
    "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
    "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
    swap result and tmp
    Now result has
    {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
    "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
    "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }

*/

// class Solution {
// public:
//     vector<string> dial = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) return {};
//         vector<string> result;
//         result.push_back("");

//         for (auto digit : digits) {
//             vector<string> tmp;
//             for (auto candidate : dial[digit - '0']) {
//                 for (auto s : result) {
//                     tmp.push_back(s + candidate);
//                 }
//             }
//             result.swap(tmp);
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<string> dial = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        queue<string> que;
        vector<string> ans;

        que.push("");
        while (!que.empty()) {
            string curr = que.front();
            que.pop();

            if (curr.length() == digits.length()) {
                ans.push_back(curr);
            }

            else {
                string s = dial[digits[curr.length()] - '0'];
                for (auto x : s) {
                    que.push(curr + x);
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<string> dial = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

//     vector<string> letterCombinations(string digits) {
//         vector<string> ans;
//         if (digits.empty()) return ans;
//         backtrack(digits, 0, "", ans);
//         return ans;
//     }

//     void backtrack(const string& digits, int index, string current, vector<string>& ans) {
//         if (index == digits.length()) {
//             ans.push_back(current);
//             return;
//         }

//         string letters = dial[digits[index] - '0'];
//         for (char letter : letters) {
//             backtrack(digits, index + 1, current + letter, ans);
//         }
//     }
// };

int main() {
    Solution s = Solution();
    string input;

    input = "23456";
    std::cout << s.letterCombinations(input) << std::endl;

    // input = "53382633";
    // std::cout << s.letterCombinations(input) << std::endl;

    // input = "2";
    // std::cout << s.letterCombinations(input) << std::endl;
    return 0;
}
