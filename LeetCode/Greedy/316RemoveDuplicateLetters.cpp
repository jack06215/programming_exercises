#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {

        unordered_map<char, int> last;     // last index of every char
        vector<bool> visited(26);          // check if the character is visited
        string ans = "";

        // store the last index of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            // skip if already visited
            if (visited[s[i] - 'a']) {
                continue;
            }

            // if s[i] is smaller than last character of ans and last index of the 
            // character is greater than i, we can delete the last character of
            // answer as it will come after i later
            while (!ans.empty() && ans.back() > s[i] && last[ans.back()] > i) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);                // add the current character to answer
            visited[s[i] - 'a'] = true;         // mark the current node visited
        }
        return ans;
    }
};

int main() {
    string s = "bcabc";
    cout << Solution().removeDuplicateLetters(s) << endl;

    return 0;
}
