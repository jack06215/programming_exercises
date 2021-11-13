#include <iostream>
#include "comm.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    string root = "[4,2,7,1,3,6,9]";
    cout << root << endl;
    cout << serialize(s.invertTree(deserialize(root))) << endl;
    return 0;
}

