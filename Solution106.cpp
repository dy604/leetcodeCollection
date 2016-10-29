
//题目106，Construct Binary Tree from Inorder and Postorder Traversal 由中序和后序遍历建立二叉树
//题目105，Construct Binary Tree from Preorder and Inorder Traversal 由先序和中序遍历建立二叉树

class solution {
public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int inorderSize = inorder.size();
        int postorderSize = postorder.size();
        if (inorderSize==0 || inorderSize!=postorderSize)
            return nullptr;
        TreeNode* root = recursionBuild(inorder, 0, inorderSize-1, postorder, 0, postorderSize-1);
        return root;
    }
    TreeNode* recursionBuild(vector<int> &inorder, int inLeft, int inRight, vector<int> &postorder, int postLeft, int postRight) {
        if (inLeft > inRight)
            return nullptr;
        int i = 0;
        TreeNode* node = new TreeNode(postorder[postRight]);
        for (i=inLeft; i<=inRight; i++) {
            if (inorder[i] == node->val)
                break;
        }
        node->left = recursionBuild(inorder, inLeft, i-1, postorder, postLeft, postLeft+i-inLeft-1);
        node->right = recursionBuild(inorder, i+1, inRight, postorder, postLeft+i-inLeft, postRight-1);
        return node;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty())
            return nullptr;
        int size = postorder.size();
        TreeNode* root = new TreeNode(postorder[size-1]);
        TreeNode* cur = root;
        stack<TreeNode*> stacks;
        stacks.push(root);
        int flag = 1;
        int post_index = size-2;
        int in_index = size-1;
        while (post_index >= 0) {
            if (!stacks.empty() && stacks.top()->val==inorder[in_index]) {
                cur = stacks.top();
                flag = 0;
                stacks.pop();
                in_index--;
            } else {
                TreeNode* tmp = new TreeNode(postorder[post_index]);
                if (flag == 1) {
                    cur->right = tmp;
                    cur = cur->right;
                } else {
                    cur->left = tmp;
                    cur = cur->left;
                    flag = 1;
                }
                stacks.push(tmp);
                post_index--;
            }
        }
        return root;
    }
};
