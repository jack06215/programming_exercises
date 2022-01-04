#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int len = boxTypes.size();
        sort(begin(boxTypes), end(boxTypes),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1];
            });
        int totUnits = 0;
        for (int i = 0; i < len; i++) {
            int boxes = boxTypes[i][0];
            int unitsPer = boxTypes[i][1];
            if (truckSize >= boxes) {
                truckSize -= boxes;
                totUnits += boxes * unitsPer;
            }
            else {
                totUnits += truckSize * unitsPer;
                break;
            }
        }
        return totUnits;
    }
};