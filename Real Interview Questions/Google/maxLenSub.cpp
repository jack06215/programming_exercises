/*
    [Google Phone Interview]
    Question：

    Given a set S of 10^6 doubles. 
    Find a number X so that the [X, X+1) half-open real interval contains as many elements of S as possible.

    For example, given this subset:

    [2.7, 0.23, 8.32, 9.65, -6.55, 1.55, 1.98, 7.11, 0.49, 2.75, 2.95, -96.023, 0.14, 8.60]
    the value X desired is 1.98 because there are 4 values in the range 1.98 to 2.97999

    [1.98, 2.7, 2.75, 2.95]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double maxLenSub(vector<double>& subset) {
    int size = subset.size();
    if(size == 0) {
        return 0.0f;
    }
    sort(subset.begin(), subset.end());
    
    double X = numeric_limits<double>::min();
    int begin{0}, end{0}, best_len{1};
    while(end < size) {
        // keep increasing `end` until its total hits 1 or higher
        // then adjust the `begin` so the range is [X, X+1)
        ++end;        
        while(subset[end] - subset[begin] >= 1) {
            ++begin;
        }

        // we found the new bigger subset
        if(end - begin + 1 > best_len) {
            best_len = end - begin + 1;
            X = subset[begin];
        }
    }
    return X;
}

int main(int argc, char const *argv[]) {
    vector<double> subset = { 2.7, 0.23, 8.32, 9.65, -6.55, 1.55, 1.98, 7.11, 0.49, 2.75, 2.95, -96.023, 0.14, 8.60 };
    cout << maxLenSub(subset) << endl;
    return 0;
}
