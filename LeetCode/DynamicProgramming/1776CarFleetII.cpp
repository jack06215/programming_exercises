#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        auto position = [&](int i) { return cars[i][0]; };
        auto speed = [&](int i) { return cars[i][1]; };
        // compute the collision time t between car i and car j.
        auto collide_time = [&](int next_car, int current_car) {
            return static_cast<double>(position(current_car) - position(next_car)) / (speed(next_car) - speed(current_car));
        };

        // collision time of the i-th car.
        vector<double> time(cars.size(), -1);

        // which car has been collided by the i-th car.
        vector<int> collide(cars.size(), -1);
        cout << collide << endl;
        cout << time << endl << endl;
        for (int current_car = cars.size() - 2; current_car >= 0; current_car--) {
            int next_car = current_car + 1;

            int v = speed(current_car);
            int p = position(current_car);

            // find next possible collide car 
            // for the i-th car, if its speed larger than the i+1s' than we know it must collided with i+1 car
            // otherwise, we can check if the i-th car collided with the car which collided by the i+1 car. 

            // for example, for car [i, i+1, i+2] we have [2,4,1], 
            // we know ith car(speed 2) cannot collided with i+1 car(speed 4) but it can collided with i+2 car (speed 1).
            while (next_car != -1 && v <= speed(next_car)) {
                next_car = collide[next_car];
            }
            if (next_car == -1) {
                continue;
            }

            // calculate collide time
            double t = collide_time(next_car, current_car);

            // car i collided with car j after car j collided with another car. 
            // In such case, the speed of car j will changed after the first collision, so the time t is not accuracy. 
            // Because we know in such case car j will collided with some car j', and it happens before car i collided car j, 
            // we can simplly make j = j' and recompute time t.
            while (time[next_car] != -1 && t >= time[next_car]) {
                next_car = collide[next_car];
                t = collide_time(next_car, current_car);
            }

            time[current_car] = t;
            collide[current_car] = next_car;
            cout << collide << endl;
            cout << time << endl << endl;
        }
        return time;
    }
};

int main() {
    vector<vector<int>> cars = read2DVectorFromString("[[1,2],[2,1],[4,3],[7,2]]");
    Solution().getCollisionTimes(cars);
    return 0;
}
