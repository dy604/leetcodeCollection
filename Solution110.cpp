
//题目110，Balanced Binary Tree 平衡二叉树

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getDepth(root->left)-getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balancedHeight(root) >= 0;
    }
    int balancedHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = balancedHeight(root->left);
        int right = balancedHeight(root->right);
        if (left<0 || right<0 || abs(left-right)>1) return -1;
        return max(left, right)+1;
    }
};
