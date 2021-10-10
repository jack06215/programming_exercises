#include <vector>
#include <string>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:   
    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            vector<int> P(CHAR_SIZE, 0);
            for(int j = i; j < s.length(); j++) {
                ++P[s[j] - 'a']; 
                
                if(P[s[j] - 'a'] < k) continue;
                
                if(check(&P[0], k)) {
                    ans = max(ans, j - i + 1);
                }
            }
            cout << P << endl;
        }
        return ans;
    }
private:
    const int CHAR_SIZE = 26;
    bool check(int arr[], int k){
        for(int i = 0; i < CHAR_SIZE; i++)
            if(arr[i] != 0 && arr[i] < k) return false;
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.longestSubstring("aaabb", 3) << endl;
    return 0;
}

