#include <stack>
#include <queue>
#include <vector>
#include "../binarytree.h"

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if ((p && !q) || (!p && q)) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// DFS with stack
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode* >> dfs;
        dfs.emplace(p, q);
        while (!dfs.empty()) {
            auto [p, q] = dfs.top();
            if (!p ^ !q || (p && q && p->val != q->val)) {
                break;
            }
            dfs.pop();
            if (p && q) {
                dfs.emplace(p->right, q->right);
                dfs.emplace(p->left, q->left);
            }
        }
        return dfs.empty();
    }
};

// BFS with queue
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> bfs;
        bfs.emplace(p, q);
        while (!bfs.empty()) {
            auto [p, q] = bfs.front();
            if (!p ^ !q || (p && q && p->val != q->val)) {
                break;
            }
            bfs.pop();
            if (p && q) {
                bfs.emplace(p->left, q->left);
                bfs.emplace(p->right, q->right);
            }
        }
        return bfs.empty();
    }
};
