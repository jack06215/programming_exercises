#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <iostream>
#include <vector>
#include "../prettyprint.h"

template <typename T> void insertion_sort(T start, T end) {
    for (auto i = start; i != end; ++i) {
        std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
    }
}

int main() {
    std::vector<int> arr{4, 8, 6, -1, -2, -3, -1, 3, 4, 5};
    insertion_sort(arr.begin(), arr.begin());

    std::cout << arr << std::endl;
    return 0;
}