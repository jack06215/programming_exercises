#include <iostream>
#include <vector>
#include "../../prettyprint.h"
#include "../../binarytree.h"

using namespace std;
/*
    TreeNode* root = deserialize("[4, 2, 6, 1, 3, 5, 7]");
    cout << serialize(root) << endl;
*/
// [4, 2, 6, 1, 3, 5, 7]
TreeNode* insert_re(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }
    if (val > node->val) {
        node->right = insert_re(node->right, val);
    }
    else {
        node->left = insert_re(node->left, val);
    }
    return node;
}

/*
    For duplicate, add an vector<int> counter (same size as insert goes)
    and if new element insert it's 1, and when duplicate is insert add counter[val] by 1 and so forth
*/

TreeNode* search_node(TreeNode* node, int val) {
    TreeNode* iter = node;
    while (iter != nullptr && val != iter->val) {
        if (val < iter->val) {
            iter = iter->left;
        }
        else {
            iter = iter->right;
        }
    }
    return iter == nullptr ? new TreeNode(-1) : iter;
}

void inorder_print(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inorder_print(node->left);
    cout << node->val << ' ';
    inorder_print(node->right);
}

int main(int argc, char const* argv[]) {
    TreeNode* root;
    root = insert_re(root, 4);
    root = insert_re(root, 2);
    root = insert_re(root, 6);
    root = insert_re(root, 1);
    root = insert_re(root, 3);
    root = insert_re(root, 5);
    root = insert_re(root, 7);
    // cout << serialize(root) << endl;
    // inorder_print(root);
    cout << serialize(search_node(root, 0)) << endl;
    return 0;
}
