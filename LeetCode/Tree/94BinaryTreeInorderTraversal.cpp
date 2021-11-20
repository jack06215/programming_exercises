#include <vector>
#include <iostream>
#include <stack>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

class SolutionRecursive {
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

/*
    Inorder先拜訪左子節點，再拜訪父節點，最後拜訪右子節點。
    我們需要盡量往左子節點前進，而途中經過的父節點們就先存在一個stack裡面，
    等到沒有更多左子節點時，就把stack中的父節點取出並拜訪其右子節點。
*/

class SolutionRecursive {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == nullptr) {
            return arr;
        }
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* node = stk.top(); stk.pop();
                arr.push_back(node->val);
                curr = node->right;
            }
        }
        return arr;
    }
};