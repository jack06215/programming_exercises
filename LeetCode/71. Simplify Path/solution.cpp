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
            if (token == "." || token == "") continue;
            else if (token == "..") {
                if (!dir.empty()) {
                    dir.pop_back();
                }
            }
            else dir.push_back(token);
        }
        if (dir.empty()) return "/";
        for (const auto& it: dir) {
            result += '/' + it;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    string input = "/a/../../b/../c//.//";
    return 0;
}

