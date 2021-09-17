#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {        
        // size of num1 and num2 respectively
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        
        // iterator for nums1 and num2 respectively
        int j = 0;
        int k = 0;
        
        // current and previous value respectively
        int x = 0;
        int y = 0;
        
        // as soon as pointer reaches (m + n)/2, exit the loop.
        int i = 0;
        while(i <= ((n + m) / 2)) {
            y = x;
            // unless nums2 reached the end, pick whichever is smaller from both array
            if(k >= m || (j < n && nums1[j] < nums2[k])) {
                x = nums1[j++];
            }
            else {
                x = nums2[k++];
            }
            i++;
            cout << x << " " << y << endl;
        }
        if((n + m) % 2 == 0)
            return (double)(x + y) / 2;
        return (double)x;
    }
};