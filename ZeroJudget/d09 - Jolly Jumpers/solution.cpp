#include <iostream>
#include <vector>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

int main() {
	vector<int> arr = { 4, 1, 4, 2, 3 };
	// vector<int> arr = { 5, 1, 4, 2, -1, 6 };
	
	vector<int> freq(arr.size(), 0);
	for (int i = 0; i < arr.size() - 1; ++i) {
		freq[abs(arr[i + 1] - arr[i])] ++;
	}
	
	bool is_jolly = true;
	for (int i = 1; i < freq.size() - 1; ++i) {
		if (freq[i] == 0) {
			is_jolly = false;
			break;	
		}
	}
	cout << is_jolly << endl;
	return 0;
}
