#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {        
        // size of num1 and num2 respectively
        int n = nums1.size();
        int m = nums2.size();
        
        // iterator for nums1 and num2 respectively
        int j = 0;
        int k = 0;
        
        // current and previous value respectively
        int x = 0;
        int y = 0;
        
        // begin the loop of binart search as if the both arrays were mergerd and sorted
        // as soon as the pointer reaches the middle, exit the loop.
        int i = 0;
        while(i <= ((n + m) / 2)) {
            y = x;
            // store whichever is smaller in var x from both array, then increment 1 step
            // if (k >= m) , then nums2 is finished so we loop through the remaining nums1
            //   until nums1 also finished, i.e. (j < n)
            if(k >= m || (j < n && nums1[j] < nums2[k])) {
                x = nums1[j++];
            }
            else {
                x = nums2[k++];
            }
            i++;       
        }
        // odd length return x, even return the average of x and y
        if((n + m) % 2 == 0)
            return (double)(x + y) / 2;
        return (double)x;
    }
};