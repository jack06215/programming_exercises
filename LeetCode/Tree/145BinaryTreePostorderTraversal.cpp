#include <vector>
#include <stack>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;


/*
    Postorder需先拜訪左右子節點，最後拜訪父節點。遍歷每個節點時，
    將父節點和左右子節點都放進stack中，並將父節點的左右子節點設為NULL。
    當stack pop出一個節點沒有左右子節點時，表示他的左右子節點已經被拜訪過了，
    則可以拜訪父節點。
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        stk.push(root);

        while (stk.size()) {
            TreeNode* node = stk.top();
            if (!node->left && !node->right) {
                stk.pop();
                res.push_back(node->val);
            }

            if (node->right) {
                stk.push(node->right);
                node->right = nullptr;
            }

            if (node->left) {
                stk.push(node->left);
                node->left = nullptr;
            }
        }
        return res;
    }
};