#include <vector>
#include <iostream>
#include <unordered_map>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

            // if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                return {hash[numberToFind], i};
            }
            // number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return {-1};
    }
};

int main(void) {
    Solution s = Solution();
    
    vector<int> input = {2,7,11,15};
    int target = 10;

    cout << s.twoSum(input, target) << endl;
    return 0;
}