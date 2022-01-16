#include <algorithm>    // min_element, iter_swap, upper_bound, rotate
                        // partition, inplace_merge, make_heap, sort_heap
                        // push_heap, pop_heap, is_heap, is_sorted
#include <cassert>
#include <functional>   // less
#include <iterator>     // distance, begin, end, next
#include <random>

#include <iostream>
#include <vector>
#include "prettyprint.h"

const int kRangeFrom = -1000000;  // first of range for random number generator
const int kRangeTo = 1000000;     // last of range for random number generator
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(kRangeFrom, kRangeTo);

template <class FwdIt, class Compare = std::less<>>
void insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{}) {
    for (auto it = first; it != last; ++it) {
        auto const insertion = std::upper_bound(first, it, *it, cmp);
        std::rotate(insertion, it, std::next(it)); 
    }
}

template <class FwdIt, class Compare = std::less<>>
void selection_sort(FwdIt first, FwdIt last, Compare cmp = Compare{}) {
    for (auto it = first; it != last; ++it) {
        auto const selection = std::min_element(it, last, cmp);
        std::iter_swap(selection, it); 
    }
}

template<class It>
std::pair<It, It> three_way_partition(It first, It last) {
    assert(first != last);    
    const auto pivot = *--last;

    auto i = first, j = first, k = last;
    while (j != k)
        if (*j < pivot)
            std::iter_swap(i++, j++);
        else if (*j > pivot)
            std::iter_swap(j, --k);
        else
            ++j;

    std::iter_swap(j++, last);
    return {i, j};
}

template <class FwdIt, class Compare = std::less<>>
void quick_sort(FwdIt first, FwdIt last, Compare cmp = Compare{}) {
	auto const N = std::distance(first, last);
	if (N <= 1)  {
        return;
    }
	auto const pivot = std::next(first, N / 2);
	std::nth_element(first, pivot, last, cmp);
	quick_sort(first, pivot, cmp);
	quick_sort(pivot, last, cmp);
}

template <class FwdIt>
void quick_sort_three_way(FwdIt first, FwdIt last) {
	auto const N = std::distance(first, last);
	if (N <= 1)  {
        return;
    }
	const auto p = three_way_partition(first, last);
	quick_sort_three_way(first, p.first);
	quick_sort_three_way(p.second, last);
}

template<class It, class Gen>
void randomized_quick_sort(It first, It last, Gen&& gen) {
    if (last - first <= 1)
        return;

    std::uniform_int_distribution<std::ptrdiff_t> dist(0, last - first - 1);
    std::iter_swap(first + dist(gen), last - 1);
    
    const auto p = three_way_partition(first, last);
    randomized_quick_sort(first, p.first, gen);
    randomized_quick_sort(p.second, last, gen);
}


template<class BiDirIt, class Compare = std::less<>>
void merge_sort(BiDirIt first, BiDirIt last, Compare cmp = Compare{}) {
    auto const N = std::distance(first, last);
    if (N > 1) {
        auto const middle = std::next(first, N / 2);
        merge_sort(first, middle, cmp);
        merge_sort(middle, last, cmp);
        std::inplace_merge(first, middle, last, cmp);
    }
}

template<typename ForwardIterator>
void counting_sort(ForwardIterator first, ForwardIterator last) {
    if (first == last || std::next(first) == last) return;

    auto minmax = std::minmax_element(first, last);  // avoid if possible.
    auto min = *minmax.first;
    auto max = *minmax.second;
    if (min == max) return;

    using difference_type = typename std::iterator_traits<ForwardIterator>::difference_type;
    std::vector<difference_type> counts(max - min + 1, 0);

    for (auto it = first ; it != last ; ++it) {
        ++counts[*it - min];
    }

    for (auto count: counts) {
        first = std::fill_n(first, count, min++);
    }
}

namespace lib {
    template<class RandomIt, class Compare = std::less<>>
    void make_heap(RandomIt first, RandomIt last, Compare cmp = Compare{})
    {
        for (auto it = first; it != last;) {
            std::push_heap(first, ++it, cmp); 
            assert(std::is_heap(first, it, cmp));           
        }
    }

    template<class RandomIt, class Compare = std::less<>>
    void sort_heap(RandomIt first, RandomIt last, Compare cmp = Compare{})
    {
        for (auto it = last; it != first;) {
            std::pop_heap(first, it--, cmp);
            assert(std::is_heap(first, it, cmp));           
        } 
    }
}

template<class RandomIt, class Compare = std::less<>>
void heap_sort(RandomIt first, RandomIt last, Compare cmp = Compare{})
{
    lib::make_heap(first, last, cmp);
    lib::sort_heap(first, last, cmp);
}

int main() {
    // generate random data of size kSize
    const int kSize = 100;
    std::vector<int> arr(kSize);
    std::generate(arr.begin(), arr.end(), [&](){ return dist(mt); });
    
    // counting_sort(arr.begin(), arr.end());
    
    // heap_sort(arr.begin(), arr.end());
    
    // insertion_sort(begin(arr), end(arr));
    
    // quick_sort(begin(arr), end(arr));
    
    // selection_sort(begin(arr), end(arr));
    
    // merge_sort(begin(arr), end(arr));
    
    randomized_quick_sort(begin(arr), end(arr), std::mt19937{});

    // quick_sort_three_way(begin(arr), end(arr));
    
    std::cout << std::is_sorted(arr.begin(), arr.end()) << std::endl;
    return 0;
}