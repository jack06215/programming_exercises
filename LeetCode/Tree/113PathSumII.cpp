#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, stk);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> stk;
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        targetSum = targetSum - root->val;
        // we reach the end of node
        if (!root->left && !root->right) {
            // valid path is found
            if (targetSum == 0) {
                ans.push_back(path);
            }
        }
        else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        // backtracking
        path.pop_back();
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.pathSum(deserialize("[5,4,8,11,null,13,4,7,2,null,null,5,1]"), 22) << endl;
    return 0;
}
