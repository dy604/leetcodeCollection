
//题目257，Binary Tree Paths 二叉树路径

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode *root, string out, vector<string> &res) {
        out += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(out);
        } else {
            if (root->left) dfs(root->left, out + "->", res);
            if (root->right) dfs(root->right, out + "->", res);
        }
    }
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        left.insert(left.end(), right.begin(), right.end());
        for (auto &a : left) {
            a = to_string(root->val) + "->" + a;
        }
        return left;
    }
};
