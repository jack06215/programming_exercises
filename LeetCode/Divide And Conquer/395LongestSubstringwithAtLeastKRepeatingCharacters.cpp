#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return _longestSubstring(0, s.length(), s, k);
    }
public:
    int _longestSubstring(int start, int end, string s, int k) {
        // frequency of each character in string
        vector<int> counter(26);
        for (int i = start; i < end; i++) {
            counter[s[i] - 'a']++;
        }

        // check if substring contains same characters, if yes then return the length of substring
        int flag = 1;
        for (int i = 0; i < 26; i++) {
            if (counter[i] > 0 && counter[i] < k) {
                flag = 0;
            }
        }
        if (flag) {
            return end - start;
        }

        // split string at character whose frequency is less than k
        for (int i = start; i < end; i++) {
            int count = counter[s[i] - 'a'];
            if (count > 0 && count < k) {
                int lhs = _longestSubstring(start, i, s, k);
                int rhs = _longestSubstring(i + 1, end, s, k);
                return max(lhs, rhs); // return max length from left and right substring
            }
        }
        // length of substring
        return end - start;
    }
};