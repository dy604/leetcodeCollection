
//题目94，Binary Tree Inorder Traversal 二叉树的中序遍历

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> inStack;
        TreeNode *curNode = root;

        while (curNode || !inStack.empty()) {
            if (curNode) {
                inStack.push(curNode);
                curNode = curNode->left;
            } else {
                curNode = inStack.top();
                inStack.pop();
                res.push_back(curNode->val);
                curNode = curNode->right;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
    void inorderTraversal(TreeNode *root, vector<int> &res) {
        if (!root) return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *curNode = root;
        while (curNode) {
            if (curNode->left) {
                TreeNode *prev = curNode->left;
                while (prev->right && prev->right!=curNode)
                    prev = prev->next;
                if (!prev->right) {
                    prev->right = curNode;
                    curNode = curNode->left;
                } else {
                    prev->right = NULL;
                    res.push_back(curNode->val);
                    curNode = curNode->right;
                }
            } else {
                res.push_back(curNode->val);
                curNode = curNode->right;
            }
        }
        return res;
    }
};
