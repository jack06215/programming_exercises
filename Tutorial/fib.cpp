#include <iostream>
#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cctype>

using namespace std;

auto generate_n_fibonacci(uint64_t n) {
	vector<uint64_t> fib(n, 1);
	transform(fib.cbegin(),
			  fib.cend() - 2,
			  fib.cbegin() + 1,
			  fib.begin() + 2,
			  plus{});
	return fib;
}

int main (void) {
	auto result = generate_n_fibonacci(50);
	for(const auto& val: result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}