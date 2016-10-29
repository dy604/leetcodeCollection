
//题目113，Path Sum II 二叉树路径之和之二
//题目112，Path Sum

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        pathSum(root, sum, cur, res);
        return res;
    }
private:
    void pathSum(TreeNode* root, int gap, vector<int> &cur, vector<vector<int>> &res) {
        if (root == nullptr) return;
        cur.push_back(root->val);
        if (root->left==nullptr && root->right==nullptr) {
            if (gap == root->val)
                res.push_back(cur);
        }
        pathSum(root->left, gap-root->val, cur, res);
        pathSum(root->right, gap-root->val, cur, res);
        cur.pop_back();
    }
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<int> onePath;
        onePath.push_back(root->val);
        pathSum_DFS(root, sum, onePath, res);
        return res;
    }
private:
    void pathSum_DFS(TreeNode* root, int sum, vector<int> &onePath, vector<vector<int>> &res) {
        if (root->left==NULL && root->right==NULL && root->val==sum) {
            res.push_back(onePath);
            return ;
        }
        if (root->left) {
            onePath.push_back(root->left->val);
            pathSum_DFS(root->left, sum-root->val, onePath, res);
            onePath.pop_back();
        }
        if (root->right) {
            onePath.push_back(root->right->val);
            pathSum_DFS(root->right, sum-root->val, onePath, res);
            onePath.pop_back();
        }
    }
};
