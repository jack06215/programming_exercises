#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = needle.size();
        int n2 = haystack.size();
        if (n1 == 0) {
            return 0;
        }
        if (n1 > n2) {
            return -1;
        }

        int p1 = 0;
        int p2 = 0;
        int p_start = -1;

        while (p1 < n1 && p2 < n2) {
            // starting position (initially starts from 0)
            p_start = p2;

            // move pointer until they dont match anymore
            while (p1 < n1 && p2 < n2 && haystack[p2] == needle[p1]) {
                p1++;  // next needle char
                p2++;  // next haystack char
            }
            // end of string
            if (p1 == n1) {
                return p_start;
            }
            else {
                p1 = 0; // reset neddle
                p2 = p_start + 1; // next starting position
            }
        }
        return -1;
    }
};

int main(int argc, const char* argv[]) {
    cout << Solution().strStr("hello", "hello") << endl;
    return 0;
}
