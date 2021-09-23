#include <iostream>
#include <vector>
#include "prettyprint.h"

using namespace std;

int power(int value, int exponent) {
    if (exponent == 0) return 1;
    else if (exponent == 1) return value;
    if (value == 0) return 0;

    return (value * power(value, exponent - 1));
}

int main(int argc, char const *argv[]) {
    cout << power(3, 3) << endl;
    return 0;
}
