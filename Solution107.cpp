
//题目107，Binary Tree Level Order Traversal II 二叉树层序遍历之二
//题目102，Binary Tree Level Order Traversal
//题目103，Binary Tree Zigzag Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 1, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void traverse(TreeNode* root, int level, vector<vector<int>> &res) {
        if (!root) return;
        if (level > res.size())
            res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        traverse(root->left, level+1, res);
        traverse(root->right, level+1, res);
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> oneLevel;
            int size = q.size();
            for (int i=0; i<size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                oneLevel.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(oneLevel);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> oneLevel;
            int size = q.size();
            for (int i=0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                oneLevel.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};
