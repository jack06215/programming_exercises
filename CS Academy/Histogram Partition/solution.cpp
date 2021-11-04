#include <stack>
#include <iostream>

using namespace std;

int n;
stack<int> stk;

void read() {
    cin >> n;
}

int main() {
    read();
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int val = 0;
        if (i < n) cin >> val;
        
        while (!stk.empty() && stk.top() > val) {
            stk.pop();
            ++ans;
        }
        
        if (stk.empty() || stk.top() < val) {
            stk.push(val);
        }
    }
    cout << ans << endl;
}