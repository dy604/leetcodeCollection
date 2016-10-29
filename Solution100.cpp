
//题目100，Same Tree 判断相同树

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.push(p);
        stk.push(q);
        while (!stk.empty()) {
            p = stk.top(); stk.pop();
            q = stk.top(); stk.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            stk.push(p->left);
            stk.push(q->left);
            stk.push(p->right);
            stk.push(q->right);
        }
        return true;
    }
};
