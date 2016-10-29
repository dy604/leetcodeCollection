
//题目105，Construct Binary Tree from Preorder and Inorder Traversal 由先序和中序遍历建立二叉树
//题目106，Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
    template<typename InputIterator>
    TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last, InputIterator in_first, InputIterator in_last) {
        if (pre_first == pre_last)
            return nullptr;
        if (in_first == in_last)
            return nullptr;
        auto root = new TreeNode(*pre_first);
        auto RootPos = find(in_first, in_last, *pre_first);
        auto leftSize = distance(in_first, RootPos);
        root->left = buildTree(next(pre_first), next(pre_first, leftSize+1), in_first, next(in_first, leftSize));
        root->right = buildTree(next(pre_first, leftSize+1), pre_last, next(RootPos), in_last);
        return root;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = 0;
        for (i=iLeft; i<=iRight; ++i) {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft+1, pLeft+i-iLeft, inorder, iLeft, i-1);
        cur->right = buildTree(preorder, pLeft+i-iLeft+1, pRight, inorder, i+1, iRight);
        return cur;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *cur = root;
        stack<TreeNode*> stacks;
        stacks.push(root);
        int flag = 0;
        int pre_index = 1;
        int in_index = 0;
        while (in_index < inorder.size()) {
            if (!stacks.empty() && stacks.top()->val==inorder[in_index]) {
                cur = stacks.top();
                flag = 1;
                stacks.pop();
                ++in_index;
            } else {
                TreeNode* tmp = new TreeNode(preorder[pre_index]);
                if (flag == 0) {
                    cur->left = tmp;
                    cur = cur->left;
                } else {
                    cur->right = tmp;
                    cur = cur->right;
                    flag = 0;
                }
                stacks.push(tmp);
                ++pre_index;
            }
        }
        return root;
    }
};
