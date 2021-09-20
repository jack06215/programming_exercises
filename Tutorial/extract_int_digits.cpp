#include <stack>
#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;

    std::stack<int> sd;
    while (number > 0) {
        int digit = number%10;
        number /= 10;
        sd.push(digit);
    }

    while (!sd.empty()) {
        int digit = sd.top(); sd.pop();
        cout << digit << endl;
    }
}

