#include <stack>
#include <iostream>
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top(), stk.pop();

            if (pre != nullptr && root->val <= pre->val) {
                return false;
            }
            pre = root;
            root = root->right;
        }
        return true;
    }
};