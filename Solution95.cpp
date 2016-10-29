
//题目95，Unique Binary Search Trees II 独一无二的二叉搜索树之二
//题目96，Unique Binary Search Trees

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
private:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> subTree;
        if (start > end) {
            subTree.push_back(nullptr);
            return subTree;
        }
        for (int k=start; k<=end; k++) {
            vector<TreeNode*> leftSubs = generate(start, k-1);
            vector<TreeNode*> rightSubs = generate(k+1, end);
            for (auto i : leftSubs) {
                for (auto j : rightSubs) {
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};
