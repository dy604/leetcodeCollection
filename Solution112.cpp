
//题目112，Path Sum 二叉树的路径和
//题目113，Path Sum II

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr)
            return sum == root->val;

        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
