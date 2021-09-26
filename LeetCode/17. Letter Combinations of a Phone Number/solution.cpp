#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombination(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        unordered_map<int, string> m = {
            {1, ""}, {2, "abc"},
            {3, "def"}, {4, "ghi"},
            {5, "jkl"}, {6, "mno"},
            {7, "pqrs"}, {8, "tuv"},
            {9, "wxyz"},
        };
        result = {{""}};
        for (int i = 0; i < digits.size(); i++) {
            string no = m[static_cast<int>(digits[i] - '0')];
            vector<string> temp;
            for (int j = 0; j < result.size(); j++) {
                for (int k = 0; k < no.size(); k++) {
                    temp.push_back(result[j] + no[k]);
                }
            }
            result = temp;
        }
        return result;
    }

};

int main () {
    Solution s = Solution();
    string input;

    input = "236";
    std::cout << s.letterCombination(input) << std::endl;
    
    input = "24";
    std::cout << s.letterCombination(input) << std::endl;

    input = "2";
    std::cout << s.letterCombination(input) << std::endl;
    return 0;
}