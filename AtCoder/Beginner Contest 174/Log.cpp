#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int n; 					// number of logs
int k;					// number of cuts
double nums[200010]; 	// lengths of each log

// a very small number
float eps = numeric_limits<float>::epsilon();

bool can(double len, int num_cuts) {
	int64_t res = 0;
	for(int i = 0; i < n; ++i) {
		// how many smaller logs can we cut
		int64_t t = nums[i] / len;
		if(nums[i] - t * len > eps) {
            t++;
        }
		// add up to total cuts
		res += t - 1;
		// false number of cut is over the given constraint
		if(res > k) return false;
	}	
	return true;
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> nums[i];
	
	double left = numeric_limits<double>::min();
    double right = numeric_limits<double>::max();
	
	while(left < right - eps) {
		double mid = left + (right - left) / 2;
		// can we cut all logs such that its length is <= `mid` within `k` cuts
		if(can(mid, k)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
    cout << ceil(right) << endl;
	return 0;
}
