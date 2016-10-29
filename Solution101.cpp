
//题目101，Symmetric Tree 判断对称树

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root ? isSameTree(root->left, root->right) : true;
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val==right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

class Solution {
public:
    bool isSymetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            auto p = s.top(); s.pop();
            auto q = s.top(); s.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
    }
};

class Solution {
public:
    bool isSymetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();
            if ((node1 && !node2) || (!node1 && node2)) return false;
            if (node1) {
                if (node1->val != node2->val) return false;
                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->left);
                q2.push(node2->right);
            }
        }
        return true;
    }
};
