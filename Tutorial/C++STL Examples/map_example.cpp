#include <map>
#include <string>
#include <iostream>
#include "prettyprint.h"

using namespace std;



int main() {
    // map<string, int> mapstring;
    // map<int, string> mapint;
    // map<string, char> mapstring;
    // map< char, string> mapchar;
    // map<char, int> mapchar;
    // map<int, char> mapint;

    map<int, string> maplive;
    maplive.insert({ 102,"aclive" });
    maplive.insert({ 321, "hai" });
    maplive[112] = "April";
    cout << maplive << endl;
}

// maplive
// maplive.insert({ 102,"aclive" });
// maplive.insert(map<int, string>::value_type(321, "hai"));
// maplive[112] = "April";