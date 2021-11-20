#include <iostream>
#include <vector>
#include "prettyprint.h"
#include "binarytree.h"

class Solution {
public:
    vector<int> leftView(TreeNode* root) {
        _leftView(root, 1);
        return ans;
    }
private:
    vector<int> ans;
    int maxLevel = 0;

    void _leftView(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (maxLevel < level) {
            ans.push_back(root->val);
            maxLevel = level;
        }
        _leftView(root->left, level + 1);
        _leftView(root->right, level + 1);
    }
};

int main(int argc, char const* argv[]) {
    TreeNode* root = deserialize("[1,2,3,null,5,null,4]");
    cout << Solution().leftView(root) << endl;
    return 0;
}
