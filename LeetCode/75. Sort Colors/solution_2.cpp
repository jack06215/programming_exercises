#include <vector>

using namespace std;

class Solution {
public:
     void sortColors(vector<int>& nums) {
       // begin, end, current pointer respectively
       int begin = 0;
       int end = nums.size() - 1;
       int curr = 0;
       
       // keep moving forward until current reach the end;
        while(curr <= end) {  
            // if 0 then swap with current and begin
            if(nums[curr] == 0) {
                swap(nums[begin++], nums[curr++]);
            }
            // if 1 then just move the current ahead
            else if(nums[curr] == 1) {
                curr++;
            }
            // if 2 then swap begin and end
            else if(nums[curr] == 2) {
                swap(nums[end--], nums[curr]);
            }
        }
	}
};
