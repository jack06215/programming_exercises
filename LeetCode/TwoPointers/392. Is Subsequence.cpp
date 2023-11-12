#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();

        int iter_s = 0;
        int iter_t = 0;
        while (iter_s < len_s && iter_t < len_t) {
            if (s[iter_s] == t[iter_t]) {
                iter_s++;
            }
            iter_t++;
        }
        return iter_s == len_s ? true : false;
    }
};
