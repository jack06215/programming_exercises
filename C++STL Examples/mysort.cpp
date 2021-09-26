#include <random>
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>
#include "prettyprint.h"

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, 10000);

void merge(vector<int>& array, int front, int mid, int end) {
    vector<int> left_arr(begin(array) + front, begin(array) + mid + 1);
    vector<int> right_arr(begin(array) + mid + 1, begin(array) + end + 1);

    left_arr.insert(left_arr.end(), numeric_limits<int>::max());      // 在left_arr尾端加入值為max元素
    right_arr.insert(right_arr.end(), numeric_limits<int>::max());    // 在left_arr尾端加入值為max元素

    int lidx{0}, ridx{0};
    for (int i = front; i <= end; i++) {
        if (left_arr[lidx] <= right_arr[ridx] ) {                     // 左邊元素較小
            array[i] = left_arr[lidx];
            lidx++;
        }
        else {                                                        // 右邊元素較小
            array[i] = right_arr[ridx];
            ridx++;
        }
    }
}

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

void merge_sort(vector<int>& array, int left, int right) {    
    if (left < right) {                             // 表示目前的範圍是有效的
        int mid = left + (right - left) / 2;        // mid即是將array對半分的index
        merge_sort(array, left, mid);               // 繼續切割前半段subarray
        merge_sort(array, mid + 1, right);          // 繼續切割後半段subarray
        merge(array, left, mid, right);             // 將兩個subarray做比較, 並合併出排序後的array
    }
}

void quick_sort(vector<int>& array, int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

void insertion_sort(vector<int>& array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// void quick_sort_three_way(vector<int>& array, int left, int right) {
//     if (left < right) {
//         auto pivot = three_way_partition(array);
//         cout << pivot << endl;
//         quick_sort_three_way(array, left, pivot.first - 1);
//         quick_sort_three_way(array, pivot.second + 1, right);
//     }
// }

int main() {
    const int kSize = 20;
    std::vector<int> arr(kSize);
    std::generate(arr.begin(), arr.end(), [&](){ return dist(mt); });

    cout << "original:\n" << arr << endl;
    quick_sort(arr, 0, arr.size() - 1);
    cout << "sorted:\n" << arr << endl;

    return 0;
}
