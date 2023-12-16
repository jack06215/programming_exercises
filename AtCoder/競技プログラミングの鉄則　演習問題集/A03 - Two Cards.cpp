#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution1 {
private:
  int n;
  int k;
  vector<int> P;
  vector<int> Q;

public:
  Solution1() {
    cin >> n >> k;
    P.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> P[i];
    }
    Q.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> Q[i];
    }
  }
  void solve() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (P[i] + Q[j] == k) {
          cout << "Yes" << endl;
          return;
        }
      }
    }
    cout << "No" << endl;
    return;
  }
};

class Solution2 {
private:
  int N, K;
  vector<int> P, Q;
public:
  Solution2() {
    cin >> N >> K;
    P.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> P[i];
    }
    Q.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> Q[i];
    }
  }

  void solve() {
    unordered_set<int> red_card_val;
    for (auto& p : P) {
      red_card_val.insert(p);
    }

    for (auto q : Q) {
      if (red_card_val.count(K - q) > 0) {
        cout << "Yes" << endl;
        return;
      }
    }
    cout << "No" << endl;
  }
};

int main(int argc, char* argv[]) {
  auto s = Solution2();
  s.solve();
  return 0;
}
