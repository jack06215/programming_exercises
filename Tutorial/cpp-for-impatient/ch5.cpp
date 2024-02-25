#include <cstdarg>
#include <iostream>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::function;

void pr_ints(int n ...) {
    va_list(arglist);
    va_start(arglist, n);
    for (int i = 0; i < n; ++i) {
        cout << va_arg(arglist, int) << endl;
    }
    va_end(arglist);
}

void lambda_fun() {
    auto f1 = [] (int a, int b) { return a + b; };
    cout << f1(1, 2) << endl;
}

function<int(int, int)> get_fun(int start) {
    int n = 10;
    return [n, start] (int a, int b) { return start + a + b + n; };
}

int main() {
    lambda_fun();
    auto f = get_fun(10);
    cout << f(1, 2) << endl;
    return 0;
}