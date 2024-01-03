#include <vector>
#include <iostream>
#include <stack>
#include "../../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        auto position = [&](int i) { return cars[i][0]; };
        auto speed = [&](int i) { return cars[i][1]; };
        auto collide_time = [&](int i, int j) {
            return static_cast<double>(position(j) - position(i)) / (speed(i) - speed(j));
        };

        // we use stack (LIFO) because a car can possibly merge to any car on its right
        vector<int> car_on_right;
        car_on_right.reserve(n);

        vector<double> time(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            // there are cars to right of i-th car it can merge to
            while (!car_on_right.empty()) {
                // get the next candidate car
                int j = car_on_right.back();

                // j-th (candidate) car is faster than i-th (current) car
                // thus no merge happen, so pop it off
                if (speed(i) <= speed(j)) {
                    car_on_right.pop_back();
                }
                else {
                    double t = collide_time(i, j);
                    // cars to the left of i-th car cannot merge to j-th car
                    if (time[j] != -1 && t >= time[j]) {
                        car_on_right.pop_back();
                    }
                    // merge car fleet
                    else {
                        time[i] = t;
                        break;
                    }
                }
            }
            // add i-th car,
            car_on_right.push_back(i);
        }

        return time;
    }
};
