#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int count = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            // if any vowel is inserted from right-> increment
            if (vowels.find(s[i]) != string::npos) {
                count++;

            }
            // move sliding window, and if any vowel is removed from left-> decrement
            if (i >= k && vowels.find(s[i - k]) != string::npos) {
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 };
        int res = 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += vowels[s[i] - 'a'];
            if (i >= k) {
                count -= vowels[s[i - k] - 'a'];
            }
            res = max(res, count);
        }
        return res;
    }
};