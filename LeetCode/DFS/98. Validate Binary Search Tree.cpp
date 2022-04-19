#include "../binarytree.h"

class Solution {
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
public:
    bool isValidBST(TreeNode* root) {
        return _isValid(root, nullptr, nullptr);
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}

