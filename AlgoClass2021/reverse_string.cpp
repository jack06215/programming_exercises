#include <string>
#include <iostream>
#include "prettyprint.h"

using namespace std;

string reverse_str_recursive(string str) {
    if (str.empty()) {
        return "";
    }
    return reverse_str_recursive(str.substr(1)) + str[0];
}

void reverse_str_inplace(char* str, int size) {
    if (size <= 1) {
        return;
    }
    else {
        char c = str[0];
        str[0] = str[size - 1];
        str[size - 1] = c;
        reverse_str_inplace(&str[1], size - 2);
    }
}


int main(int argc, char const *argv[]) {
    string mystr = "Hello World!";
    reverse_str_inplace(&mystr[0], mystr.size());
    // auto result = reverse_str_recursive(mystr);
    cout << mystr << endl;
    return 0;
}
