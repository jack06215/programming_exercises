#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../prettyprint.h"

/*
    User-defined literals
*/
long long operator "" _celsius(unsigned long long tempCelsius) {
  return std::llround(tempCelsius * 1.8 + 32);
}
24_celsius; // == 75

int operator "" _int(const char* str, std::size_t) {
  return std::stoi(str);
}
"123"_int

/*
    type inferring using "decltype"
*/
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}
add(1, 2)

/*
    std::tie()
*/
void foo() {
    std::string playerName;
    std::tie(std::ignore, playerName, std::ignore) = std::make_tuple(91, "John Tavares", "NYI");
}

/*
    "default" implementation of a function
*/
struct A {
  A() = default;
  A(int x) : x{x} {}
  int x {1};
};
A a; // a.x == 1
A a2 {123}; // a.x == 123

int main() {
    return 0;
}