#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        int left = 0;
        int right = n - k;
        int startIdx = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid + k == n || x - arr[mid] <= arr[mid + k] - x) {
                startIdx = mid; // Found a valid answer -> Update
                right = mid - 1; // Try to find the left most answer in the left side
            }
            else {
                left = mid + 1; // Find in the right side
            }
        }
        return vector<int>(begin(arr) + startIdx, begin(arr) + startIdx + k);
    }
};