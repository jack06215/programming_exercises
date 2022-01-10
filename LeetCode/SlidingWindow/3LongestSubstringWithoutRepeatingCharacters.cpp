#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        const int n = s.size();
        int head = 0;
        int tail = 0;
        int ans = 0;
        while (head < n && tail < n) {
            // character does not in the set 
            if (set.find(s[tail]) == set.end()) {
                set.insert(s[tail++]);            // insert the character in set, and update head pointer
                ans = max(ans, tail - head);      // check if the new distance is longer than the current answer
            }
            // character does exist in the set, i.e. it is a repeated character
            else {
                set.erase(s[head++]);  // update tail pointer, continue with the checking for substring
            }
        }
        return ans;
    }
};