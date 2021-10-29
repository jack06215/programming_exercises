#include "List.h"
#include <vector>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[]) {
    vector<int> vec = {1,2,3};
    List<int> mylist;
    for (const auto& val: vec) {
        mylist.insertNewNode(val);
    }
    mylist.print();
    return 0;
}
