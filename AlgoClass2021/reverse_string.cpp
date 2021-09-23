#include <string>
#include <iostream>
#include "prettyprint.h"

using namespace std;

void reverse_string(char* str, int size) {
    if (size <= 1) {
        return;
    }
    else {
        char c = str[0];
        str[0] = str[size - 1];
        str[size - 1] = c;
        reverse_string(&str[1], size - 2);
    }
}


int main(int argc, char const *argv[]) {
    string mystr = "Hello World!";
    reverse_string(&mystr[0], mystr.size());
    
    cout << mystr << endl;
    return 0;
}
