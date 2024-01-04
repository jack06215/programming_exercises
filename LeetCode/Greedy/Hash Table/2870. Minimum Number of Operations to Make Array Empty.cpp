#include <unordered_map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int res = 0;
        int num, count;
        for (auto iter : freq) {
            tie(num, count) = iter;
            if (count == 1) {
                return -1;
            }
            res += (count + 2) / 3;
        }
        return res;
    }
};
