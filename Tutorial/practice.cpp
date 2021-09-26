#include <iostream>
#include <vector>
#include "prettyprint.h"

using namespace std;

// void foo(vector<int> bar); // by value
// void foo(vector<int> &bar); // by reference (non-const, so modifiable inside foo)
// void foo(vector<int> const &bar); // by const-reference

void foo1(int *arr) { cout << sizeof(arr) << '\n'; }
void foo2(int arr[]) { cout << sizeof(arr) << '\n'; }
void foo3(int arr[10]) { cout << sizeof(arr) << '\n'; }
void foo4(int (&arr)[10]) { cout << sizeof(arr) << '\n'; }

void fun(double val, int val2) {

    int x2 = val;    // if val == 7.9, x2 becomes 7 (bad)

    char c2 = val2;  // if val2 == 1025, c2 becomes 1 (bad)

    int x3 {val};    // error: possible truncation (good)

    char c3 {val2};  // error: possible narrowing (good)

    char c4 {24};    // OK: 24 can be represented exactly as a char (good)

    char c5 {264};   // error (assuming 8-bit chars): 264 cannot be 
                     // represented as a char (good)

    int x4 {2.0};    // error: no double to int value conversion (good)

}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo1(arr);
    foo2(arr);
    foo3(arr);
    foo4(arr);
    
    return 0;
}