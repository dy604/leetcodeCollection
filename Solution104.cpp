
//题目104，Maximum Depth of Binary Tree 二叉树的最大深度

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++res;
            for (int i=0, n=q.size(); i<n; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left != nullptr)
                    q.push(p->left);
                if (p->right != nullptr)
                    q.push(p->right);
            }
        }
        return res;
    }
};
