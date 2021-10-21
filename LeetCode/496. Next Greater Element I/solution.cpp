#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for (int num1 : nums1) {
      ans.push_back(-1);
      int index = find(nums2.begin(), nums2.end(), num1) - nums2.begin();
      for (int i = index; i < nums2.size(); ++i)
        if (nums2[i] > num1) {
          ans.back() = nums2[i];
          break;
        }
    }
    return ans;
  }
};

class Solution2 {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> next;
    for (int num2 : nums2) {
        // 1 
        // 3 
        // 4
        // 2
      while (!s.empty() && num2 > s.top()) {
          // ()
          // ([1, 3])
          // ([1, 3], [3, 4])
          // NA
        next[s.top()] = num2;
        // NA
        // []
        // []
        s.pop();
      }
      // [1]
      // [3]
      // [4]
      // [4, 2]
      s.push(num2);
    }
    cout << next << endl;
    vector<int> ans;
    for (int num : nums1)
      ans.push_back(next.count(num) ? next[num] : -1);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    Solution2 sol;
    cout << sol.nextGreaterElement(nums1, nums2) << endl;
    return 0;
}

