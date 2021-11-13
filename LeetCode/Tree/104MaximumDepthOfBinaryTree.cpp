#include <iostream>
#include "comm.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        traverse(root, 1);
        return _maxDepth;
    }

private:
    int _maxDepth = 1;
    void traverse(TreeNode* node, int depth) {
        _maxDepth = max(_maxDepth, depth);
        if (node->left != nullptr) {
            traverse(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            traverse(node->right, depth + 1);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    TreeNode* node = deserialize("[3,9,20,null,null,15,7]");
    // cout << walkThrough(node) << endl;
    cout << s.maxDepth(node) << endl;
    return 0;
}
