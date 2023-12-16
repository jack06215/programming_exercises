#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) : bit(n + 1, 0) {}

    void update(int i, int val) {
        while (i < bit.size()) {
            bit[i] = bit[i] + val;
            i = i + lowbit(i);
        }
    }

    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans = ans + bit[i];
            i = i - lowbit(i);
        }
        return ans;
    }
private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> bit;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        // to make every element positive, and 1-indexed
        FenwickTree tree(maxx - minn + 1);

        // traverse from behind
        vector<int> count(n);
        for (int i = n - 1; i >= 0; i--) {

            // we want only smaller so subtract m[nums[i]] (count of current element)
            count[i] = tree.query(nums[i] - minn);

            // update fenwick tree (increase freq of element by 1)
            tree.update(nums[i] - minn + 1, 1);
        }

        return count;
    }
};
