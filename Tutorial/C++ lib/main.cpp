#include <iostream>
#include <string>
#include "SplitString.h"
#include "prettyprint.h"

using namespace std;

int main(int argc, char const* argv[]) {
    string str{ "the quick brown fox jumps over the lazy dog" };
    vector<string> v{ explode(str, ' ') };
    cout << v << endl;
    return 0;
}
