#include <iostream>
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    bool _isValid(TreeNode* node, TreeNode* minn, TreeNode* maxx) {
        if (node == nullptr) {
            return true;
        }
        if (minn && node->val <= minn->val) {
            return false;
        }
        if (maxx && node->val >= maxx->val) {
            return false;
        }
        return _isValid(node->left, minn, node) && _isValid(node->right, node, maxx);
    }

    bool isValidBST(TreeNode* root) {
        return _isValid(root, nullptr, nullptr);
    }
};
