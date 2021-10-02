#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include "prettyprint.h"

using namespace std;

bool cmp(auto a, pair<string, int>& b) {
  return a.second < b.second;
}

int main() {
  vector<string> arr = {"a", "b", "a", "c", "d" , "a", "c"};
  map<string, int> m;
  for (const string& ch: arr) {
    m[ch]++;
  }
//   sort(m.begin(), m.end(), cmp);

  cout << m << endl;
  return 0;
}