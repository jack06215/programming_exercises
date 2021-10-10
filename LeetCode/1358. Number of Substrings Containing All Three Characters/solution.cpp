#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;


class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};
        int res = 0;
        int i = 0;
        int n = s.size();
        for (int j = 0; j < n; ++j) {
            ++count[s[j] - 'a'];
            while (count[0] && count[1] && count[2]) {
                --count[s[i] - 'a'];
                i++;
            }
            res += i;
            cout << count << "  " << res << endl;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    /*
        [1, 0, 0]  0
        [1, 1, 0]  0
        [0, 1, 1]  1
        [1, 0, 1]  3
        [1, 1, 0]  6
        [0, 1, 1]  10
        10
    */
    cout << s.numberOfSubstrings("abcabc") << endl;
    return 0;
}

