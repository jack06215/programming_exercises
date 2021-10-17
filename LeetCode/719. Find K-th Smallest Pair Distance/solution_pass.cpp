#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tail = nums[1] - nums[0];
        for (int i = 2; i < n; i++){
            if (nums[i] - nums[i-1] < tail) {
                tail = nums[i] - nums[i-1];
            } 
        }
        int head = nums[n - 1] - nums[0];
        while (tail < head){
            int mid = tail + (head - tail) / 2;
            int count = 0;
            for(int i = 0; i < n; i++) {
                int pos = upper_bound(nums.begin(), nums.end(), nums[i] + mid) - nums.begin();
                count += pos - i - 1;
            }
            if (count < k) {
                tail = mid+1;
            }
            else
                head = mid;
        }
        return tail;
    }
};