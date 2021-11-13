#include <vector>
#include <iostream>
#include "comm.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildVector(root, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    void buildVector(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }

        if (res.size() == depth) {
            res.resize(depth + 1);
        }

        res[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
};

int main(int argc, char const* argv[]) {
    TreeNode* node;
    Solution s;

    node = deserialize("[3,9,20,null,null,15,7]");
    
    cout << s.levelOrder(node) << endl;
    return 0;
}
