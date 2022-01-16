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
        // store frequency of each character in string
        vector<int> charCount(26);
        for (int i = start; i < end; i++) {
            charCount[s[i] - 'a']++;
        }

        // check if frequency of any character in string is less than k
        int flag = 1;
        for (int i = 0; i < 26; i++) {
            if (charCount[i] > 0 && charCount[i] < k) {
                flag = 0;
            }
        }

        // if frequency of all characters is more than k, return length of string
        if (flag) {
            return end - start;
        }

        // split string at character whose frequency is less than k
        for (int i = start; i < end; i++) {
            int count = charCount[s[i] - 'a'];
            if (count > 0 && count < k) {
                int lhs = _longestSubstring(start, i, s, k);
                int rhs = _longestSubstring(i + 1, end, s, k);
                return max(lhs, rhs); // return max length from left and right substring
            }
        }
        return end - start; // return length of string
    }
};