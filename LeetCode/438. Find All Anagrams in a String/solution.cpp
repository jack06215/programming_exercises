#include <vector>
#include <iostream>
#include <unordered_map>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> lookup;
        unordered_map<char, int> map;
        for (const auto ch : p) {
            lookup[ch]++;
        }
        int len = s.size();
        int windowSize = p.size();
        for (int head = 0, tail = 0; tail < len; tail++) {
            ++map[s[tail]];
            if (tail - head == windowSize) {
                --map[s[head]];
                if (map[s[head]] == 0) {
                    map.erase(s[head]);
                }
                head++;
            }
            if (map == lookup) {
                res.push_back(head);
            }
        }
        return res;
    }
};


int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.findAnagrams("cbaebabacd", "abc") << endl;
    return 0;
}


