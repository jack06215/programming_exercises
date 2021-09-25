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

void merge(vector<int> &array, int front, int mid, int end) {
    vector<int> left_arr(begin(array) + front, begin(array) + mid + 1);
    vector<int> right_arr(begin(array) + mid + 1, begin(array) + end + 1);

    left_arr.insert(left_arr.end(), numeric_limits<int>::max());      // 在left_arr尾端加入值為max元素
    right_arr.insert(right_arr.end(), numeric_limits<int>::max());    // 在left_arr尾端加入值為max元素

    int lidx = 0;
    int ridx = 0;
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

void merge_sort(vector<int> &array, int left, int right) {    
    if (left < right) {                             // 表示目前的矩陣範圍是有效的
        int mid = left + (right - left) / 2;        // mid即是將矩陣對半分的index
        merge_sort(array, left, mid);               // 繼續divide矩陣的前半段subarray
        merge_sort(array, mid + 1, right);          // 繼續divide矩陣的後半段subarray
        merge(array, left, mid, right);             // 將兩個subarray做比較, 並合併出排序後的矩陣
    }
}

int main() {
    const int kSize = 20;
    std::vector<int> arr(kSize);
    std::generate(arr.begin(), arr.end(), [&](){ return dist(mt); });

    cout << "original:\n" << arr << endl;
    merge_sort(arr, 0, arr.size() - 1);
    cout << "sorted:\n" << arr << endl;

    return 0;
}
