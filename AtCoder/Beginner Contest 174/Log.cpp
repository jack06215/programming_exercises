#include <iostream>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

// number of logs
int n;

// number of cuts
int k;

// lengths of each log
double num[200010];

// small number
float eps = numeric_limits<float>::epsilon();

bool can(double len)
{
	int64_t rul = 0;
	for(int i = 0; i < n; i++) {
		int64_t t = num[i]/len;
		if(abs(num[i] - t * len) > eps) {
            t++;
        }
		rul += t - 1;
		if(rul > k) return false;
	}	
	return true;
}

int main()
{
	cin >> n >> k;
	for(int i=0; i<n; i++) {
        cin >> num[i];
    }
	
	double left = numeric_limits<double>::min();
    double right = numeric_limits<double>::max();
	
	while(left < right - eps) {
		double mid = (left + right)/2;
		if(can(mid)) right = mid;
		else left = mid;
	}
    cout << ceil(right) << endl;
	return 0;
}
