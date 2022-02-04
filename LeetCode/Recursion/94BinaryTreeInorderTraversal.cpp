#include <stack>
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return arr;
    }
private:
    void inorder(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> stk;
        while (true) {
            if (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            else {
                if (stk.empty()) {
                    break;
                }
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};