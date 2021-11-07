#include <iostream>
#include <string>

using namespace std;

string s;

void read() {
    cin >> s;
}

void reverseString(char* str, int size) {
    if (size <= 1) {
        return;
    }
    char ch = str[0];
    str[0] = str[size - 1];
    str[size - 1] = ch;
    reverseString(&str[1], size - 2);
}

void solve() {
    reverseString(&s[0], s.size());
}

int main(int argc, char* argv) {
    read();
    solve();
    cout << s << endl;
    return 0;
}
