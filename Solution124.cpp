
//题目124，Binary Tree Maximum Path Sum 求二叉树的最大路径和

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        maxPathSumDFS(root, res);
        return res;
    }
    int maxPathSumDFS(TreeNode* root, int &res) {
        if (!root) return 0;
        int left = maxPathSumDFS(root->left, res);
        int right = maxPathSumDFS(root->right, res);
        int top = root->val + (left>0 ? left : 0) + (right>0 ? right : 0);
        res = max(res, top);
        return max(left, right)>0 ? max(left, right) + root->val : root->val;
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(const TreeNode* root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if (l > 0) sum += l;
        if (r > 0) sum += r;
        max_sum = max(max_sum, sum);
        return max(r,l)>0 ? max(r, l)+root->val : root->val;
    }
};
