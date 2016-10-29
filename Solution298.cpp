
//题目298，Binary Tree Longest Consecutive Sequence 二叉树最长连续序列

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val - 1, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int v, int out, int &res) {
        if (!root) return;
        if (root->val == v+1) ++out;
        else out = 1;
        res = max(res, out);
        dfs(root->left, root->val, out, res);
        dfs(root->right, root->val, out, res);
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, 1, res);
        return res;
    }
    void dfs(TreeNode *root, int len, int &res) {
        res = max(res, len);
        if (root->left) {
            if (root->left->val == root->val+1) dfs(root->left, len+1, res);
            else dfs(root->left, 1, res);
        }
        if (root->right) {
            if (root->right->val == root->val+1) dfs(root->right, len+1, res);
            else dfs(root->right, 1, res);
        }
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
    int helper(TreeNode *root, TreeNode *p, int res) {
        if (!root) return res;
        res = (p && root->val == p->val+1) ? res+1 : 1;
        return max(res, max(helper(root->left, root, res), helper(root->right, root, res)));
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = 1;
            TreeNode *t = q.front(); q.pop();
            while ((t->left && t->left->val == t->val+1) || (t->right && t->right->val == t->val+1)) {
                if (t->left && t->left->val == t->val+1) {
                    if (t->right) q.push(t->right);
                    t = t->left;
                } else if (t->right && t->right->val == t->val+1) {
                    if (t->left) q.push(t->left);
                    t = t->right;
                }
                ++len;
            }
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            res = max(res, len);
        }
        return res;
    }
};
