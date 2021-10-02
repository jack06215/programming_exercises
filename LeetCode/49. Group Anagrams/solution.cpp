#include <vector>
#include <string>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> anagrams;
        for (const auto& str : strs) {
            auto key = str; 
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        for (const auto& p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    cout << s.groupAnagrams(strs) << endl;
    return 0;
}
