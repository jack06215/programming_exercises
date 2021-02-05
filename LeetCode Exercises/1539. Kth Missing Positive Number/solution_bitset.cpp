#include <bitset>
#include <iostream>
#include <vector>

int findKthPositive(const std::vector<int> &arr, const int k) {
	// set all bits to 0 (not found)
	std::bitset<1001> present;
	present.reset();
	// set i-th bit if the number is found
	for (const auto &x : arr) {
		present.set(x);
	}
	// find k-th 0 in the bitset
	for (int idx = 1, misses = 0;; idx++) {
		// 0 is found
		if (!present[idx]) {
			// i-th missing number
			misses++;
			// we found k-th missing number!
			if (misses == k) {
				return idx;
			}
		}
	}
	// for syntax correctness only
	return -1;
}

int main() {
	std::vector<int> v{1, 2, 4, 5, 6};
	std::cout << findKthPositive(v, 2) << '\n';

    return 0;
}