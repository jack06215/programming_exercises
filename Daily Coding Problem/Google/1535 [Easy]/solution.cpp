#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool findPairWithSum(const vector<int>& nums, int k) {
  unordered_map<int, bool> seen;

  for (int num : nums) {
    if (seen.find(k - num) != seen.end()) {
      // Found a pair
      return true;
    }
    seen[num] = true;
  }

  // No pair found
  return false;
}

int main() {
  vector<int> nums = { 10, 15, 3, 7 };
  int k = 17;

  if (findPairWithSum(nums, k)) {
    cout << "True: Pair found that adds up to " << k << endl;
  }
  else {
    cout << "False: No pair adds up to " << k << endl;
  }

  return 0;
}
