#include <iostream>
#include <string>

using namespace std;

bool True(string id) {
    cout << "True" << id << endl;
    return true;
}

bool False(string id) {
    cout << "False" << id << endl;
    return false;
}


int main() {
    bool result;
    result = False("A") || (False("B") && False("C"));
    // eq. False("A") || (False("B") && False("C"))
    // FalseA
    // FalseB
    // "Short-circuit evaluation skip of C"
    // A is false so we have to evaluate the right of ||,
    // B being false we do not have to evaluate C to know that the result is false



    result = True("A") || (False("B") && False("C"));
    // eq. True("A") || (False("B") && False("C"))
    cout << result << " :=====================" << endl;
    // TrueA
    // "Short-circuit evaluation skip of B"
    // "Short-circuit evaluation skip of C"
    // A is true so we do not have to evaluate
    //        the right of || to know that the result is true
    // If || had precedence over && the equivalent evaluation would be:
    // (True("A") || False("B")) && False("C")
    // What would print
    // TrueA
    // "Short-circuit evaluation skip of B"
    // FalseC
    // Because the parentheses are placed differently
    // the parts that get evaluated are differently
    // which makes that the end result in this case would be False because C is false
}
