#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int i = x;
        int n = 0;
        while (i > 0) {
            n = (i % 10) + (n * 10);
            cout << n << endl;
            i /= 10;
        }
        return n == x;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.isPalindrome(125) << endl;
    return 0;
}
