#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> counts;

        // Count characters in the first string
        for (char c : s) {
            counts[c]++;
        }

        // Subtract counts based on the second string
        for (char c : t) {
            if (counts.find(c) == counts.end() || counts[c] == 0) {
                return false;
            }
            counts[c]--;
        }

        return true;
    }
};
