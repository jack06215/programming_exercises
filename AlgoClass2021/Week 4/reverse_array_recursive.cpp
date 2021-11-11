#include <vector>
#include <iostream>
#include "prettyprint.h"

using namespace std;

/*
From section 23.2.4, point 1 of the standard:

[...] The elements of a vector are stored contiguously, 
meaning that if v is a vector where T is some type other than bool,
then it obeys the identity &v[n] == &v[0] + n for all 0 <= n < v.size().

swap 0 and 4: 5 2 3 4 1
swap 0 and 3: 4 2 3 5 1
swap 0 and 2: 3 2 4 5 1
swap 0 and 1: 2 3 4 5 1
*/


void reverse_vec_inplace(int* arr, int size) {
    if (size <= 1) {
        // nothing to be swapped
        return;
    }
    else {
        // value to be swapped
        int swap_val = arr[0];
        
        // swap left most and right most
        arr[0] = arr[size - 1];
        arr[size - 1] = swap_val;
        reverse_vec_inplace(&arr[1], size - 2);
    }
}

vector<int> reverse_vec_resursive(vector<int> vec) {
    if (vec.empty()) {
        return {};
    }
    auto result = reverse_vec_resursive(vector<int>(cbegin(vec) + 1, cend(vec)));
    result.emplace_back(vec[0]);
    return result;
}

int main(int argc, char const *argv[]) {
    vector<int> arr = { 1, 2, 3, 5 };
    cout << arr << endl;
    // reverse_vector(&arr[0], arr.size());
    cout << reverse_vec_resursive(arr) << endl;
    return 0;
}
