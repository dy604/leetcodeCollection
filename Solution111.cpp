
//题目111，Minimum Depth of Binary Tree 二叉树的最小深度

class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepth(root, false);
    }
    int minDepth(TreeNode* root, bool hasbrother) {
        if (!root) return hasbrother ? INT_MAX : 0;
        return 1+min(minDepth(root->left, root->right!=NULL), minDepth(root->right, root->left!=NULL));
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = INT_MAX;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 1));

        while (!stk.empty()) {
            auto node = stk.top().first;
            auto depth = stk.top().second;
            stk.pop();

            if (node->left == nullptr && node->right == nullptr)
                res = min(res, depth); //如果是叶子节点，更新一下最小结果
            if (node->left && res > depth)  //将左子树入栈
                stk.push(make_pair(node->left, depth + 1));
            if (node->right && res > depth)  //将右子树入栈
                stk.push(make_pair(node->right, depth + 1));
        }
        return res;
    }
};
