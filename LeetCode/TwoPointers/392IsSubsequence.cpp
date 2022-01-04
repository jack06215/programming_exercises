#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz_s = s.size();
        int sz_t = t.size();
        
        int i = 0;
        int j = 0;
        while (i < sz_s && j < sz_t) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == sz_s ? true : false;
    }
};
