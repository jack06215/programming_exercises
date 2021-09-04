#include <iostream>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;

int main (void) {
	vector<int> arr = { 1, 2, 3 };
	auto sum = reduce(arr.cbegin(), arr.cend(), 1, multiplies{});
	cout << sum << endl;
	
	vector<int> v = { 1, 2, 3 };
	auto rms = transform_reduce(v.cbegin(), v.cend(), v.cbegin(), 0, plus{}, 
								multiplies{});
	cout << rms << endl;
	
	vector<int> vec = { 2, 1, 2, 4, 2, 3, 5, 2, 4, 7 };
	vector<int> result(vec.size(), 0);
	partial_sum(vec.cbegin(), vec.cend(), result.begin(), [](auto a, auto b) { return max(a, b); });
	auto ans = transform_reduce(vec.cbegin(), vec.cend(), result.cbegin(), 0, plus{}, 
							[](auto a, auto b) {return abs(a - b);});
	cout << ans << endl;
	return 0;
}
