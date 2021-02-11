#include <iostream>
#include <vector>
#include <numeric>
#include "../prettyprint.h"

template <class T>
void moving_sum (const std::vector<T>& in, int num, std::vector<T>& out)
{
    // cummulative sum
    std::partial_sum (in.begin(), in.end(), out.begin());

    // shift and subtract
    for (int i = out.size() - 1, j = 0; i >= 0; i--) {
        j = i - num;
        if (j >= 0)
            out[i] -= out[j];
    } 
}

int main() {
    std::vector<double> arr_in{4, 8, 6, -1, -2, -3, -1, 3, 4, 5};
    std::vector<double> arr_out(arr_in.size());
    moving_sum (arr_in, 3, arr_out);

    std::cout << arr_out << std::endl;
    return 0;
}
