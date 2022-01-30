#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        _reverseString(s, 0, s.size() - 1);
    }
private:
    void _reverseString(vector<char>& s, int left, int right) {
        if (left >= right) {
            return;
        }
        swap(s[left], s[right]);
        _reverseString(s, left + 1, right - 1);
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        function<void(int, int)> _reverseString = [&](int left, int right) {
            if (left >= right) {
                return;
            }
            swap(s[left], s[right]);
            _reverseString(left + 1, right - 1);
        };
        _reverseString(0, s.size() - 1);
    }
};
