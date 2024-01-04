#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int len = flowerbed.size();
        int n_flowers = 0;
        for (int i = 0; i < len; i++) {
            if (
                (flowerbed[i] == 0) &&
                (i - 1 < 0 || flowerbed[i - 1] != 1) &&
                (i + 1 == len || flowerbed[i + 1] != 1)
            ) {
                n_flowers++;
                flowerbed[i] = 1;
            }
            if (n_flowers >= n) {
                return true;
            }
        }
        return false;
    }
};
