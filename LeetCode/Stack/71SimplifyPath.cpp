#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "../prettyprint.h"


using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        istringstream tokenizer(path);

        vector<string> dir;
        string token;
        while (getline(tokenizer, token, '/')) {
            cout << dir << endl;
            // no change
            if (token == "." || token == "") {
                continue;
            }
            // back to parent directory, skip if it's already root directory
            else if (token == "..") {
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
        if (dir.empty()) {
            return "/";
        }

        // make conanical directory
        for (const auto& it : dir) {
            res += '/' + it;
        }
        return res;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        string token;
        vector<string> stk;
        istringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == ".." && !stk.empty()) {
                stk.pop_back();
            }
            else if (token != "..") {
                stk.push_back(token);
            }
        }
        for (auto str : stk) {
            res += "/" + str;
        }
        return res.empty() ? "/" : res;
    }
};

int main(int argc, char const* argv[]) {
    string input = "/a/../../b/../c//.//";
    cout << Solution().simplifyPath(input) << endl;
    return 0;
}

