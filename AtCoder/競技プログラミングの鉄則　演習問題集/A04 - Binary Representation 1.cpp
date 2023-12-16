#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class Solution {
private:
  int n;
  const int N_DIGITS = 10;

public:
  Solution() {
    cin >> n;
  }
  void solve() {
    string s;
    s.resize(N_DIGITS);
    deque<string> que;

    while (n > 0) {
      div_t result = div(n, 2);
      n = result.quot;
      que.push_back(to_string(result.rem));
    }

    int stk_sz = que.size();
    for (int i = 0; i < N_DIGITS - stk_sz; i++) {
      s[i] = '0';
    }
    for (int i = N_DIGITS - stk_sz; i < N_DIGITS; i++) {
      auto c = *que.back().c_str();
      que.pop_back();

      s[i] = c;
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
