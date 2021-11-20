#include <iostream>
#include <vector>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        _view(root, 1);
        return ans;
    }
private:
    vector<int> ans;
    int maxLevel = 0;

    void _view(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (maxLevel < level) {
            ans.push_back(root->val);
            maxLevel = level;
        }
        _view(root->right, level + 1);
        _view(root->left, level + 1);
    }
};
