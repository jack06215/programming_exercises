#include <vector>
#include <iostream>
#include <queue>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int next = 0;
        int fuelStock = 0;
        int count = 0;
        priority_queue<int> pq;
        pq.push(startFuel);
        while (!pq.empty()) {
            int current = pq.top(); pq.pop();
            fuelStock += current;

            // we reached the target, return number of refuel
            if (fuelStock >= target) {
                return count;
            }
            
            // with the current fuel stock, look for farest fuel station it can reach
            while (next < stations.size() && fuelStock >= stations[next][0]) {
                pq.push(stations[next][1]);
                next++;
            }
            // add counter
            count++;
        }

        // target not reached, return -1
        return -1;
    }
};