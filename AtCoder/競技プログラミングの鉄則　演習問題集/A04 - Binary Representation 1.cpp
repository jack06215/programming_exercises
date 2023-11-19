#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class Solution {
private:
  int n;
  int res_sz = 10;

public:
  Solution() {
    cin >> n;
  }
  void solve() {
    string s;
    s.resize(res_sz);
    deque<string> que;

    while (n > 0) {
      div_t result = div(n, 2);
      n = result.quot;
      que.push_back(to_string(result.rem));
    }

    int stk_sz = que.size();
    for (int i = 0; i < res_sz - stk_sz; i++) {
      s[i] = '0';
    }
    for (int i = res_sz - stk_sz; i < res_sz; i++) {
      char c = *que.back().c_str();
      s[i] = c;
      que.pop_back();
    }
    cout << s << endl;
    return;
  }
};

int main(int argc, char* argv[]) {
  auto s = Solution();
  s.solve();
  return 0;
}
