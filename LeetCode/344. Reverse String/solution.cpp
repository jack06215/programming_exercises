#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    void swap(int left, int right, std::vector<char>& s) {
        // The base case: if the left part are passed over the midpoint
        if (left >= right) {
            return;
        }
        // swap two end
        std::swap(s[left], s[right]);
        // move two pointers one step further
        swap(left + 1, right - 1, s);
    }

    void reverseString(std::vector<char>& s) {
        swap(0, s.size() - 1, s);
    }
};

class Solution2 {
public:
    void reverseString(std::vector<char>& s) {
        for (int left = 0, right = s.size() - 1; left < right; right--, left++) {
            std::swap(s[left], s[right]);
        }
    }
};

class Solution3 {
public:
    void reverseString(std::vector<char>& s) {
        return std::reverse(s.begin(), s.end());
    }
};

class Solution5 {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1) return;
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            swap(s[head++], s[tail--]);
        }
    }
};

int main() {
    Solution s = Solution();
    std::vector<char> input_seq;

    input_seq = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    s.reverseString(input_seq);
    std::cout << input_seq << std::endl;
    return 0;
}