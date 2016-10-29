
//题目230，Kth Smallest Element in a BST 二叉搜索树中的第K小的元素

public class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        while (node.left != null) {
            stack.push(node);
            node = node.left;
        }
        while (k>0 && (node!=null || !stack.isEmpty())) {
            if (node == null) {
                node = stack.pop();
                if (--k == 0)
                    return node.val;
                node = node.right;
            } else {
                stack.push(node);
                node = node.left;
            }
        }
        return node.val;
    }
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            ++cnt;
            if (cnt == k)
                return p->val;
            p = p->right;
        }
        return 0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return 0;
        int leftSize = treeSize(root->left);
        if (k == leftSize+1) {
            return root->val;
        } else if (leftSize >= k) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k-leftSize-1);
        }
    }
    int treeSize(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + treeSize(root->left) + treeSize(root->right);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestDFS(root, k);
    }
    int kthSmallestDFS(TreeNode* root, int &k) {
        if (!root) return -1;
        int val = kthSmallestDFS(root->left, k);
        if (!k)
            return val;
        if (!--k)
            return root->val;
        return kthSmallestDFS(root->right, k);
    }
};
