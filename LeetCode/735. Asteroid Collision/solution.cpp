#include <stack>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0 ; i < asteroids.size(); ++i) {
            const int size = asteroids[i];
            // right direction
            if (size > 0) res.push_back(size);
            // left direction
            else {
                // still OK when all are negtives
                if (res.empty() || res.back() < 0) res.push_back(size);
                
                // either both destroyed, or one destroy the other
                else if (abs(res.back()) <= abs(size)) {
                    // the current asteroid destroy the other, and still alive
                    if (abs(res.back()) < abs(size)) --i;
                    // destory the top one moving right
                    res.pop_back();
                }                    
            }
        }
        return res;
    }
};