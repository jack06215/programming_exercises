#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include "../prettyprint.h"

using namespace std;

int getDigit(int number, int digit) {
    return number / static_cast<int>(pow(10, digit)) % 10;
}

vector<int> getDigits(int number) {
    deque<int> dq;

    do {
        div_t res = div(number, 10);
        dq.push_back(res.rem);
        number = res.quot;
    } while (number > 0);

    return vector<int>(dq.begin(), dq.end());
}

int main() {
    cout << getDigit(234567, 1) << endl;
    cout << getDigits(234567) << endl;

    return 0;
}
