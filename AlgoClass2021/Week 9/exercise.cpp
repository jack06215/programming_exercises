#include <iostream>
#include <stack>
#include <queue>
#include <vector>

#include "../prettyprint.h"

using namespace std;

stack<int> stk;

struct TreeNode {
    int val;
    TreeNode(int val = 0) : val(val), left(nullptr), right(nullptr) {}
    TreeNode* left;
    TreeNode* right;
};

void print_preorder(TreeNode* iter) {
    if (iter != nullptr) {
        cout << iter->val << endl;
    }
    if (iter->left != nullptr) {
        print_preorder(iter->left);
    }
    if (iter->right != nullptr) {
        print_preorder(iter->right);
    }
}


vector<int> print_bfs(TreeNode* node) {
    vector<int> res;
    queue<TreeNode*> q;
    TreeNode* iter = node;
    q.push(node);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        res.push_back(node->val);
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    return res;
}

// void insertBinaryTree(TreeNode* iter, int val) {
//     if (iter->left == nullptr) {
//         iter->left = new TreeNode(val);
//     }
//     else if (iter->right == nullptr) {

//     }
// }



int main() {
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);


    // print_preorder(root);
    cout << print_bfs(root) << endl;

    return 0;
}
