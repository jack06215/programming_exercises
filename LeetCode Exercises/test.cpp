#include <iostream>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
 
int main() {
    int n, num, a, b;
    while(cin >> n) {
        if (n == 0) break;
        priority_queue<int, vector<int>, greater<int>> pq;
        uint64_t count = 0;
        for(int i = 0; i < n; ++i) {
            cin >> num;
            pq.push(num);
        }
        for(int i = 0; i < n-1; ++i) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            count += a + b;
            pq.push(a + b);
        }
        cout << count << endl;
    }
}