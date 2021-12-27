#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <type_traits>
#include <cstring>

using namespace std;

template<typename T, typename S>
void string2vector(T str) {
    S str_c = str;
    str_c = str_c.substr(1, str_c.size() - 2);
    if (is_same<S, string>::value) {
        cout << "string\n";
    }
    else if (is_same<S, int>::value) {
        cout << "integer\n";
    }
}