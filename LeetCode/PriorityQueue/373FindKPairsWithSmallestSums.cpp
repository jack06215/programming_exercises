#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <unordered_set>
#include "../prettyprint.h"

using namespace std;

vector<int> nums1, nums2;
int k;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;
        vector<vector<int>> res;
        if (m == 0 || n == 0) {
            return res;
        }
        for (int i = 0; i < m; i++) {
            // sum, { index_of_nums1,  0 }
            pq.push({ { nums1[i] + nums2[0] }, { i, 0 } });
        }
        while (!pq.empty() && k-- > 0) {
            int val = pq.top().first;
            
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            vector<int> v = { nums1[i], nums2[j] };
            res.push_back(v);
            if (j + 1 == n) {
                continue;
            }
            pq.push({ { nums1[i] + nums2[j + 1] }, { i, j + 1 } });
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         priority_queue<pair<int, pair<int, int>>> pq;
//         unordered_set<int> s1, s2;
//         for (int i = 0; i < nums1.size(); i++) {
//             if (s1.find(nums1[i]) != s1.end()) continue;
//             for (int j = 0; j < nums2.size(); j++) {
//                 if (s2.find(nums2[j]) == s2.end()) {
//                     int sum = nums1[i] + nums2[j];
//                     if (pq.size() < k) {
//                         pq.push({ sum, { nums1[i], nums2[j] } });
//                     }
//                     else if (sum < pq.top().first) {
//                         pq.pop();
//                         pq.push({ sum, { nums1[i], nums2[j] } });
//                     }
//                 }
//                 s2.insert(nums2[j]);
//             }
//             s1.insert(nums1[i]);
//         }
//         vector<vector<int>> ans;
//         while (!pq.empty()) {
//             ans.push_back({ pq.top().second.first,pq.top().second.second });
//             pq.pop();
//         }
//         // reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };