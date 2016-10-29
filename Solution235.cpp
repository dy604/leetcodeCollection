
//题目235，Lowest Common Ancestor of a Binary Search Tree 二叉搜索树的最小共同父节点
//题目236，Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, ListNode* p, ListNode* q) {
        while (true) {
            if (root->val > max(p->val, q->val))
                root = root->left;
            else if (root->val < min(p->val, q->val))
                root = root->right;
            else
                break;
        }
        return root;
    }
};
