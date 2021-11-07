#include <vector>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int max_bulb = 0;
        int moment = 0;
        int size = light.size();
        
        for (int i = 0; i < size; i++) {
            max_bulb = max(max_bulb, light[i]);
            if (max_bulb == i + 1) {
                moment++;
            }
        }
        return moment;
    }
};
