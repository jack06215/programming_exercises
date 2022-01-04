#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include "../prettyprint.h"

using namespace std;

void optimalDigitsRemoval(const string& s, int K) {
    stack<char> stk;
    string res;

    for (int i = 0; i < s.size(); i++) {
        while (K > 0 && !stk.empty() && s[i] > stk.top()) {
            stk.pop();
            K--;
        }
        stk.push(s[i]);
    }
    
    while (K--) {
        stk.pop();
    }

    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main() {
    int N, K;
    cin >> N >> K;
    string input;
    cin >> input;
    optimalDigitsRemoval(input, K);
}
