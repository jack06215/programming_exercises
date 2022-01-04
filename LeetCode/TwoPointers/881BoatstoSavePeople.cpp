#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        int result = 0;
        std::sort(people.begin(), people.end());
        
        // two pointer strategy
        int current = 0;
        int tail = people.size() - 1;

        // let heavier person aboard first, two poeple if we can fit both
        while (current <= tail) {
            // two people on board, so we step forward
            if (people[current] + people[tail] <= limit) {
                current++;
            }
            // only one person on board (heavier people)
            tail--;
            result++;
        }
        return result;
    }
};
