#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
    int quickSelect(vector<int>& arr, int start, int end, int k) {
        /**
         * Use pivotIndex as the seperater. If k is smaller than the length of the 
         * right side of the array, the target is in the right side of the array. 
         * If k is larger, the target is in the left side of the array. 
         */
        int pivotIndex = partition(arr, start, end);
        if (k < arr.size() - pivotIndex) {
            return quickSelect(arr, pivotIndex + 1, end, k);
        } else if (k > arr.size() - pivotIndex) {
            return quickSelect(arr, start, pivotIndex - 1, k);
        }
        // pivotIndex is the index of the target if k equals to the length of the 
        // right side of the array.
        return arr[pivotIndex];
    };
    
    int partition(vector<int>& array, int left, int right) {
        int pivot = array[right];
        int i = left -1;
        for (int j = left; j < right; j++) {
            if (array[j] < pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
        i++;
        swap(array[i], array[right]);
        return i;
    }
};
