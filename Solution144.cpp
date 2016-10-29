
//题目144，Binary Tree Preorder Traversal 二叉树的先序遍历

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        repreTra(root, res);
        return res;
    }
    void repreTra(TreeNode* root, vector<int> &res) {
        if (root != nullptr) {
            res.push_back(root->val);
            repreTra(root->left, res);
            repreTra(root->right, res);
        }
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        const TreeNode *p;
        stack<const TreeNode*> stk;
        p = root;
        if (p != nullptr) stk.push(p);
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            res.push_back(p->val);
            if (p->left!=nullptr) stk.push(p->left);
            if (p->right!=nullptr) stk.push(p->right);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur;
        cur = root;
        while (cur != nullptr) {
            if (cur->left==nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* node = cur->left;
                while (node->right!=nullptr && node->right!=cur)
                    node = node->right;
                if (node->right == nullptr) {
                    res.push_back(cur->val);
                    node->right = cur;
                    cur = cur->left;
                } else {
                    node->right = nullptr;
                    cur = cur->right;
                }
            }

        }
        return res;
    }
};
