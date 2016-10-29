
//题目98，Validate Binary Search Tree 验证二叉搜索树

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode *root, long mn, long mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        for (int i=0; i<vals.size()-1; ++i) {
            if (vals[i]>=vals[i+1])
                return false;
        }
        return true;
    }
    void inorder(TreeNode *root, vector<int> &vals) {
        if (!root) return ;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};

class Solution {
public:
    TreeNode *pre;
    bool isValidBST(TreeNode *root) {
        int res = 1;
        pre = NULL;
        inorder(root, res);
        if (res == 1) return true;
        else return false;
    }
    void inorder(TreeNode *root, int &res) {
        if (!root) return ;
        inorder(root->left, res);
        if (!pre) {
            pre = root;
        } else {
            if (root->val <= pre->val) res = 0;
            pre = root;
        }
        inorder(root->right, res);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        TreeNode *pre = NULL;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            if (!pre) {
                pre = p;
            } else {
                if (p->val <= pre->val) return false;
            }
            pre = p;
            p = p->right;
        }
        return true;
    }
};
