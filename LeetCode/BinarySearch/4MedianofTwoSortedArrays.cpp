#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int num1_len = nums1.size();
        const int num2_len = nums2.size();
        const int len = num1_len + num2_len;
        const int mid = len / 2;

        // iterator for nums1 and num2 respectively
        int iter1 = 0;
        int iter2 = 0;

        // current and previous value respectively
        int x = 0;
        int y = 0;

        // begin the loop of binary search as if the both arrays were mergerd and sorted
        // as soon as the pointer reaches the middle, exit the loop.
        int i = 0;
        while (i <= mid) {
            y = x;
            if (iter2 >= num2_len || (iter1 < num1_len && nums1[iter1] < nums2[iter2])) {
                x = nums1[iter1++];
            }
            else {
                x = nums2[iter2++];
            }
            i++;
        }
        // odd length return x, even return the average of x and y
        if (len % 2 == 0) {
            return (x + y) / 2.0;
        }
        return static_cast<double>(x);
    }
};