#include <iostream>
#include <cstdint>

using namespace std;

uint64_t power(uint64_t base, uint64_t exp) {
    if (exp <= 1) {
        return (exp == 0) ? 1 : base;
    }
    if (base == 0) {
        return 0;
    }
    return base * power(base, exp - 1);
}


int main(int argc, char const* argv[]) {
    cout << power(2, 50) << endl;
    return 0;
}