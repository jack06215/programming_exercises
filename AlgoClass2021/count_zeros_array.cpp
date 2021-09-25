#include <iostream>
#include <vector>

using namespace std;

int count_zeros_recursive(int* nums, int size) {
	if(size == 0) return 0;
	int count = count_zeros_recursive(nums, size - 1);
	if (nums[size - 1] == 0) count++;
	return count;
}

int main(int argc, char *argv[]) {
	vector<int> arr = { 0, 1, 2, 3, 4, 0, 0 };
	cout << count_zeros_recursive(&arr[0], arr.size());
	return 0;
}
