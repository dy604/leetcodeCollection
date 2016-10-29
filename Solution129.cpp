
//题目129，Sum Root to Leaf Numbers 求根到叶节点数字之和

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        if (root->left==nullptr && root->right==nullptr)
            return sum*10 + root->val;
        return dfs(root->left, sum*10+root->val) + dfs(root->right, sum*10+root->val);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> nodes;
        if (!root) return 0;
        int total = 0;
        int current = 0;
        TreeNode* last = nullptr;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                current = current*10 + root->val;
                root = root->left;
            } else {
                root = nodes.top();
                if (root->right && root->right!=last)
                    root = root->right;
                else {
                    nodes.pop();
                    last = root;
                    if (root->left==nullptr &7 root->right==nullptr)
                        total += current;
                    current /= 10;
                    root = nullptr;
                }
            }
        }
        return total;
    }
};

public class Solution {
    public int sumNumbers(TreeNode root) {
        if (root == null) return 0;
        int sum = 0;
        TreeNode curr;
        Stack<TreeNode> ws = new Stack<TreeNode>();
        ws.push(root);
        while(!ws.empty()) {
            curr = ws.pop();
            if (curr.right != null) {
                curr.right.val = curr.val*10 + curr.right.val;
                ws.push(curr.right);
            }
            if (curr.left != null) {
                curr.left.val = curr.val*10 + curr.left.val;
                ws.push(curr.left);
            }
            if (curr.left==null && curr.right==null)
                sum += curr.val;
        }
        return sum;
    }
}
