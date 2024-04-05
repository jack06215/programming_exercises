#include <unordered_map>
#include <vector>

using  namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // [val, frequency]
        unordered_map<int, int> st;

        // pointer i at the begin of the window
        // pointer j at the end of the window
        int i = 0, j = 0;
        for (; j < nums.size(); j++) {
            // when the size of the window increases than the given size then remove element at the front of the window
            // here we are using maps so we will do map[key]--
            if (j > k) {
                st[nums[i++]]--;
            }
            // check if the current element has seen before in the window
            // if freq is greater than 0 then it means it was present in the window size
            if (st[nums[j]] > 0) {
                return true;
            }
            
            // if the above cases are not applicable then we simply insert the current element into the map
            st[nums[j]]++;
        }

        return false;
    }
};