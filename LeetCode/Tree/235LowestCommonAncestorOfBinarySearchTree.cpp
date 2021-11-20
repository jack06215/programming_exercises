#include <iostream>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

// (node->left->val) < (node->val) < (node->right->val)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root->val > p->val) && (root->val > q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if ((root->val < p->val) && (root->val < q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

class SolutionIterative {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            }
            else if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            }
            else {
                break;
            }
        }
        return cur;
    }
};
