#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
  string myStr;

public:
  Solution() {
    cin >> myStr;
  }
  void solve() {
    cout << "Hello " << myStr << "!" << endl;
  }
};

int main(int argc, char* argv[]) {
  auto s = Solution();
  s.solve();
  return 0;
}
