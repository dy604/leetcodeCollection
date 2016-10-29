
//题目199，Binary Tree Right Side View 二叉树的右侧视图

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int size = q.size();
            for (int i=0; i<size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> right;
        if (!root) return right;
        rightView(root, right, 0);
        return right;
    }
    void rightView(TreeNode *node, vector<int> &right, int level) {
        if (!node) return;
        if (level == right.size())
            right.push_back(node->val);
        rightView(node->right, right, level+1);
        rightView(node->left, right, level+1);
    }
};
