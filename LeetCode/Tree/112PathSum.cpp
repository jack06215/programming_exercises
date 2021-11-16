#include <iostream>
#include <vector>
#include "../binarytree.h"

using namespace std;

vector

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)  {
            return false;
        }
        if(root->right == root->left)  {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val) ;
    }
};

int main(int argc, char const *argv[]) {
    cout << boolalpha << Solution().hasPathSum(deserialize("[5,4,8,11,null,13,4,7,2,null,null,null,1]"), 22) << endl;
    return 0;
}

