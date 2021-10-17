#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include "../prettyprint.h"


using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result{""}, token{};
        istringstream tokenizer(path);
        vector<string> dir;
        while (getline(tokenizer, token, '/')) {
            // no change
            if (token == "." || token == "") continue;
            // back to parent directory
            else if (token == "..") {
                // skip if it's already root directory
                if (!dir.empty()) {
                    dir.pop_back();
                }
            }
            // go inner directory
            else {
                dir.push_back(token);
            }
        }
        // root directory
        if (dir.empty()) return "/";
        
        // make conanical directory
        for (const auto& it: dir) result += '/' + it;
        return result;
    }
};

int main(int argc, char const *argv[]) {
    string input = "/a/../../b/../c//.//";
    Solution s;
    cout << s.simplifyPath(input) << endl;
    return 0;
}

