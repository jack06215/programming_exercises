#include <queue>
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            auto current = que.front();
            que.pop();
            // Current node has a left child
            if (current->left) {
                // Left child is a leaf node
                if (!current->left->left && !current->left->right) {
                    res += current->left->val;
                }
                else {
                    que.push(current->left);
                }
            }
            // Push the right child to the queue
            if (current->right) {
                que.push(current->right);
            }
        }

        return res;
    }
};
