#include <iostream>
#include <vector>
#include <stack>
#include "../prettyprint.h"
#include "../binarytree.h"

using namespace std;

class SolutionRecursive {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
private:
    void preorder(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) {
            return;
        }
        arr.push_back(node->val);
        preorder(node->left, arr);
        preorder(node->right, arr);
    }
};
/*
    Preorder需先拜訪父節點再拜訪子節點。
    利用stack實作，將stack頂端的值取出後，把左右子節點放進stack，直到stack為空。
*/
class SolutionStack {
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        stk.push(root);
        while (stk.size() > 0) {
            TreeNode* node = stk.top(); stk.pop();
            res.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }

        return res;
    }
};


int main(int argc, char const* argv[]) {
    auto root = deserialize("[1,null,2,3]");
    cout << SolutionRecursive().preorderTraversal(root) << endl;
    return 0;
}

