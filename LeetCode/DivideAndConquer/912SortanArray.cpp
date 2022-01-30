#include <vector>
#include <limits>
#include <functional>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums);
        return nums;
    }
private:
    void merge_sort(vector<int>& nums) {
        _mergeSort(nums, 0, nums.size() - 1);
    }

    void quick_sort(vector<int>& nums) {
        _quickSort(nums, 0, nums.size() - 1);
    }

    void _mergeSort(vector<int>& array, int left, int right) {
        if (left < right) {                             // 表示目前的範圍是有效的
            int mid = left + (right - left) / 2;        // mid即是將array對半分的index
            _mergeSort(array, left, mid);               // 繼續切割前半段subarray
            _mergeSort(array, mid + 1, right);          // 繼續切割後半段subarray
            merge(array, left, mid, right);             // 將兩個subarray做比較, 並合併出排序後的array
        }
    }

    void _quickSort(vector<int>& array, int left, int right) {
        if (left < right) {
            swap(array[left + rand() % (right - left + 1)], array[left]);
            int pivot = partition(array, left, right);
            _quickSort(array, left, pivot - 1);
            _quickSort(array, pivot + 1, right);
        }
    }

    void merge(vector<int>& array, int front, int mid, int end) {
        vector<int> left_arr(begin(array) + front, begin(array) + mid + 1);
        vector<int> right_arr(begin(array) + mid + 1, begin(array) + end + 1);

        // 在left_arr, right_arr尾端加入值為max元素
        left_arr.insert(left_arr.end(), numeric_limits<int>::max());
        right_arr.insert(right_arr.end(), numeric_limits<int>::max());

        int li = 0;
        int ri = 0;
        for (int i = front; i <= end; i++) {
            // 左邊元素較小
            if (left_arr[li] <= right_arr[ri]) {
                array[i] = left_arr[li];
                li++;
            }
            // 右邊元素較小
            else {
                array[i] = right_arr[ri];
                ri++;
            }
        }
    }

    int partition(vector<int>& array, int left, int right) {
        int pivot = array[right];
        int i = left - 1;
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

int main(void) {
    auto nums = stringToIntVector("[5,2,3,1]");
    cout << nums << endl;
    Solution().sortArray(nums);
    cout << nums << endl;
    return 0;
}
