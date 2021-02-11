#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <iostream>
#include <vector>
#include "../prettyprint.h"

template<class FwdIt, class Compare = std::less<>>
void insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const insertion = std::upper_bound(first, it, *it, cmp);
        std::rotate(insertion, it, std::next(it)); 
    }
}

template<class FwdIt, class Compare = std::less<>>
void selection_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const selection = std::min_element(it, last, cmp);
        std::iter_swap(selection, it); 
    }
}

template<class FwdIt, class Compare = std::less<>>
void quick_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
	auto const N = std::distance(first, last);
	if (N <= 1){ 
        return;
    }
	auto const pivot = std::next(first, N / 2);
	std::nth_element(first, pivot, last, cmp);
	quick_sort(first, pivot, cmp);
	quick_sort(pivot, last, cmp);
}

int main() {
    std::vector<int> arr{4, 8, 6, -1, -2, -3, -1, 3, 4, 5};
    // insertion_sort(begin(arr), end(arr));
    // quick_sort(begin(arr), end(arr));
    selection_sort(begin(arr), end(arr));

    std::cout << arr << std::endl;
    return 0;
}