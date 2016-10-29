
//题目156，Binary Tree Upside Down 二叉树的上下颠倒

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode* l = root->left, *r = root->right;
        TreeNode* res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* cur = root, *pre = NULL, *next = NULL, *tmp = NULL;
        while (cur) {
            next = cur->left;
            cur->left = tmp;
            tmp = cur->right;
            cur->right = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
