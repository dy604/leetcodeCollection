
//题目103，Binary Tree Zigzag Level Order Traversal 二叉树的之字形层序遍历
//题目102，Binary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 1, res, true);
        return res;
    }
    void traverse(TreeNode* root, int level, vector<vector<int>> &res, bool left_to_right) {
        if (!root) return ;
        if (level > res.size())
            res.push_back(vector<int>());
        if (left_to_right)
            res[level-1].push_back(root->val);
        else
            res[level-1].insert(res[level-1].begin(), root->val);
        traverse(root->left, level+1, res, !left_to_right);
        traverse(root->right, level+1, res, !left_to_right);
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        bool left_to_right;
        vector<int> level;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur) {
                level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
                if (left_to_right) {
                    res.push_back(level);
                } else {
                    reverse(level.begin(), level.end());
                    res.push_back(level);
                }
                level.clear();
                left_to_right = !left_to_right;
                if (q.size()>0) q.push(nullptr);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s.push(root);
        vector<int> out;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                TreeNode *cur = s1.top();
                s1.pop();
                out.push_back(cur->val);
                if (cur->left) s2.push(cur->left);
                if (cur->right) s2.push(cur->right);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
            while (!s2.empty()) {
                TreeNode* cur = s2.top();
                s2.pop();
                out.push_back(cur->val);
                if (cur->right) s1.push(cur->right);
                if (cur->left) s1.push(cur->left);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
        }
    }
};
