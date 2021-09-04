#include <algorithm>
#include <iostream>
#include <vector>
#include "../prettyprint.h"

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);
	std::sort(nums1.begin(), nums1.end());
}

int main() {
	vector<int> l1{1, 2, 3, 0, 0, 0};
	int m = 3;
	vector<int> l2{2, 5, 6};
	int n = 3;

	merge(l1, m, l2, n);

    std::cout << l1 << std::endl;
}