#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        const int g_size = g.size();
        const int s_size = s.size();
        int child = 0;
        int cookie = 0;
        int n_served = 0;
        while (child != g_size && cookie < s_size) {
            if (g[child] <= s[cookie]) {
                n_served++;
                child++;
                cookie++;
            }
            else {
                cookie++;
            }
        }
        return n_served;
    }
};
