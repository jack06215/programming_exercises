#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            const int size = asteroids[i];
            // right direction
            if (size > 0) {
                res.push_back(size);
            }
            // left direction
            else {
                int stone = res.back();
                // still OK when all are negtives
                if (res.empty() || stone < 0) {
                    res.push_back(size);
                }

                else if (abs(stone) <= abs(size)) {
                    if (abs(stone) < abs(size)) {
                        --i;
                    }
                    res.pop_back(); // destory the top one moving right
                }
            }
        }
        return res;
    }
};