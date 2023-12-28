#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
public:
    int getLength(int count) {
        // suppose a is coming 9 times , length(a9) = 2
        // count >=10 length(a15) string = 3
        if (count == 1) {
            return 1;
        }
        else {
            if (count < 10) {
                return 2;
            }
            else {
                if (count < 100) {
                    return 3;
                }
                else {
                    return 4;
                }
            }
        }
    }


    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();

        // if we make a string from i-th index to the end of string and we perform j-th deletion then ,
        // the minimum length of the encoded string.
        dp.resize(n + 1);
        for (auto& row : dp) {
            row.resize(k + 1);
        }

        for (int i = n; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                // base Case - we assign the length(n)+1-th row to 0.
                if (i == n) {
                    dp[n][j] = 0;
                    continue;
                }
                // For every Chararter we have 2 options
                // Case 1: we don't keep it in compressed string
                // Case 2: we keep it

                // Case 1
                // we assign the previously calculated substring - i.e. dp[i+1][j-1] th cell
                // in the current(as we solve the problem into smaller problems)
                dp[i][j] = j > 0 ? dp[i + 1][j - 1] : numeric_limits<int>::max();

                // Case 2
                // we have to find the current char's index end point
                int possible_del = j;
                int count = 0;
                for (int end = i; end < n && possible_del >= 0; end++) {
                    // check there are same char "bbb.." for encoding
                    if (s[end] == s[i]) {
                        count++;
                        // Find the endpoint of that char
                        // say if the char is "a" then find series of a so that we can encode it.
                        dp[i][j] = min(dp[i][j], getLength(count) + dp[end + 1][possible_del]);
                    }
                    else {
                        // this character should be deleted. to make length min.
                        possible_del--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};
