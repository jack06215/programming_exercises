#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArray(nums, 0, nums.size());
    }
private:
    TreeNode* _sortedArray(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArray(nums, start, mid);
        root->right = _sortedArray(nums, mid + 1, end);
        return root;
    }
};
