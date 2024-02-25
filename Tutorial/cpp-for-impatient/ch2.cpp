// Created on iPad.

#include <iostream>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;

enum suit{
    heart,
    diamond,
    club,
    spade
};

void goofy() {
    static int i = 1;
    cout << i++ << endl;
}

void static_fun_example() {
    goofy();
    goofy();
    goofy();
}

void enum_example() {
    suit my_card = suit::heart;
    cout << my_card << endl;
}

void deltype_example() {
    int x = 2;
    int y = 4;
    decltype(x) z = 0;
    cout << z << endl;
}

void type_promotion_example() {
    char c = 0;
    int si = 0;
    unsigned int ui = 0;
    double d = 0.0;
    if (typeid(c + c) == typeid(int)) {
        cout << "type of (char + char) is int" << endl;
    }
    if (typeid(si + ui) == typeid(unsigned)) {
        cout << "type of (int + unsigned int) ";
        cout << "is unsigned" << endl;
    }
    if (typeid(si + d) == typeid(double)) {
        cout << "type of (int + double) is double" << endl;
    }
}

int main() {
    type_promotion_example();
    return 0;
}