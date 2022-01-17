#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        _reverseString(s, 0, s.size() - 1);
    }
    void _reverseString(vector<char>& s, int left, int right) {
        if (left >= right) {
            return;
        }
        swap(s[left], s[right]);
        _reverseString(s, left + 1, right - 1);
    }
};
