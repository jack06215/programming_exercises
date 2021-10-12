#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto atMostKDistinct = [&nums](int k){
            vector<int> count(nums.size() + 1, 0);
            int res = 0;
            int i = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (count[nums[j]] == 0) {
                    --k;
                }
                count[nums[j]]++;
                
                while (k < 0) {
                    count[nums[i]]--;
                    if (count[nums[i]] == 0) {
                        ++k;
                    }
                    nums[i++];
                }
                res += j - i + 1;
            }
            return res;
        };
        return atMostKDistinct(k) - atMostKDistinct(k - 1);
    }
};

// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         auto atMostKDistinct = [&nums](int k){
//             vector<int> count(nums.size() + 1);
//             int res = 0;
//             int i = 0;
//             for (int j = 0; j < nums.size(); ++j) {
//                 if (count[nums[j]]++ == 0) {
//                     --k;
//                 }
//                 while (k < 0) {
//                     if (--count[nums[i++]] == 0) {
//                         ++k;
//                     }
//                 }
//                 res += j - i + 1;
//             }
//             return res;
//         };
//         return atMostKDistinct(k) - atMostKDistinct(k - 1);
//     }
// };


int main(int argc, char const *argv[]) {
    return 0;
}
