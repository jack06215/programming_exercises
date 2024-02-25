#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class MyClass {
public:
    int rank;
    string name;
};

void ptr_to_member_operator_1() {
    int MyClass::*ptr_to_rank = &MyClass::rank;
    MyClass obj;
    obj.*ptr_to_rank = 1;
    cout << obj.rank << endl;
}

void ptr_to_member_operator_2() {
    auto MyClass::*ptr_to_rank = &MyClass::rank;
    MyClass obj;
    MyClass *p = &obj;
    p->*ptr_to_rank = 10;
    cout << obj.rank << endl;
}

int main() {
    ptr_to_member_operator_1();
    ptr_to_member_operator_2();
    return 0;
}