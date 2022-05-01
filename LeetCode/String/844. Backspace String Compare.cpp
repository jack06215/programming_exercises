#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S2 = "";
        string T2 = "";

        for (const auto ch : s) {
            if (ch == '#') {
                if (!S2.empty()) {
                    S2.pop_back();
                }
                continue;
            }
            S2.push_back(ch);
        }

        for (const auto ch : t) {
            if (ch == '#') {
                if (!T2.empty()) {
                    T2.pop_back();
                }
                continue;
            }
            T2.push_back(ch);
        }

        return S2 == T2;
    }
};