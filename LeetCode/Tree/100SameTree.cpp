#include "comm.h"
#include <iostream>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // check structure
        if ((p != nullptr && q == nullptr) ||
            (p == nullptr && q != nullptr)) {
            return false;
        }
        
        // check value
        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    TreeNode* p = deserialize("[1,2,3]");
    TreeNode* q = deserialize("[1,2,3]");
    cout << boolalpha << s.isSameTree(p, q) << endl;
    return 0;
}
