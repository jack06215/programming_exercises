#include "../binarytree.h"
#include "../prettyprint.h"
#include <iostream>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return (abs(left_height - right_height) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* root = deserialize("[3,9,20,null,null,15,7]");
    
    cout << boolalpha << Solution().isBalanced(root) << endl;
    
    return 0;
}
