#include <iostream>
#include <unordered_map>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        ans_ = 0;
        sums_ = {{0, 1}};
        helper(root, 0, targetSum);
        return ans_;
    }
    
private:
    unordered_map<int, int> sums_;
    int ans_;
    void helper(TreeNode* root, int curr, int target) {
        if (root == nullptr) {
            return;
        }
        curr += root->val;
        ans_ += sums_[curr - target];
        sums_[curr]++;
        helper(root->left, curr, target);
        helper(root->right, curr, target);
        sums_[curr]--;
    }
};


int main(int argc, char const* argv[]) {
    unordered_map<int, int> mp;
    mp[-1] = 2;


    cout << mp[-2] << endl;
    return 0;
}

