#include <vector>

using namespace std;

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
                count++;
            } while (start != current);
        }
    }
};

class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        helper(nums, k % nums.size(), 0);    
    }
private:
    void helper(vector<int>& nums, int k, int start) {
        if (start == nums.size() - 1) {
            return;
        }
        k = k % (nums.size() - start);
        if (!k) {
            return;
        }
        for (int i = start, j = nums.size() - k; j < nums.size(); ++i, ++j) {
            swap(nums[i], nums[j]);
        }
        helper(nums, k, start + k);
    }
};

class Solution {
    // private:
    //     void reverse(vector<int>& nums, int i, int j) {
    //         while (i < j) {
    //             swap(nums[i++], nums[j--]);
    //         }
    //     }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        // Reverse the whole array
        // 7 6 5 4 3 2 1
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        // 4 5 6 7 3 2 1
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining (n - k) elements
        // 4 5 6 7 1 2 3
        reverse(nums.begin() + k, nums.end());
    }
};
