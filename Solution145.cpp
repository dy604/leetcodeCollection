
//题目145，Binary Tree Postorder Traversal 二叉树的后序遍历

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversalHelper(root, res);
        return res;
    }
private:
    void postorderTraversalHelper(TreeNode* root, vector<int> &res) {
        if (!root) return;
        if (root->left) postorderTraversalHelper(root->left, res);
        if (root->right) postorderTraversalHelper(root->right, res);
        res.push_back(root->val);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* head = root;
        while (!s.empty()) {
            TreeNode* top = s.top();
            if ((!top->left && !top->right) || top->left==head || top->right==head) {
                res.push_back(top->val);
                s.pop();
                head = top();
            } else {
                if (top->right) s.push(top->right);
                if (top->left) s.push(top->left);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        const TreeNode *p, *q;
        stack<const TreeNode*> s;
        p = root;
        do {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                if (p->right == q) {
                    res.push_back(p->val);
                    q = p;
                } else {
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());
        return res;
    }
};

class Solution {
public: //Morris后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode dummy(0), *p = &dummy, *tmp;
        dummy.left = root;
        while (p) {
            if (!(p->left))
                p = p->right;
            else {
                tmp = p->left;
                while (tmp->right && tmp->right != p)
                    tmp = tmp->right;
                if (tmp->right != p) {
                    tmp->right = p;
                    p = p->left;
                } else {
                    tmp->right = nullptr;
                    morrisReverse(ans,p->left,tmp);
                    p = p->right;
                }
            }
        }
        return ans;
    }
    void morrisReverse(vector<int>& ans, TreeNode* start, TreeNode* end) {
        TreeNode *pre, *tmp, *psuedo = new TreeNode(0);
        pre = psuedo;
        while (start != end) {
            tmp = start->right;
            start->right = pre;
            pre = start;
            start = tmp;
        }
        start->right = pre;
        pre = nullptr;
        while (start->right) {
            ans.push_back(start->val);
            tmp = start->right;
            start->right = pre;
            pre = start;
            start = tmp;
        }
        delete psuedo;
    }
};
