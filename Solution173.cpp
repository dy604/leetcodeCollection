
//题目173，Binary Search Tree Iterator 二叉搜索树迭代器

public class BSTIterator {

    private Stack<TreeNode> stack = new Stack<TreeNode>();

    public BSTIterator(TreeNode root) {
        pushAll(root);
    }
    public boolean hasNext() {
        return !stack.isEmpty();
    }
    public int next() {
        TreeNode tmpNode = stack.pop();
        pushAll(tmpNode.right);
        return tmpNode.val;
    }
    private void pushAll(TreeNode node) {
        for (; node!=null; stack.push(node), node = node.left);
    }
}

class SBTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }
    bool hasNext() {
        return !mystack.empty();
    }
    int next() {
        TreeNode *tmpNode = mystack.top();
        mystack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
private:
    stack<TreeNode*> mystack;
    void pushAll(TreeNode *node) {
        for ( ; node!=NULL; mystack.push(node), node=node->left);
    }
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }
    bool hasNext() {
        !mystack.empty();
    }
    int next() {
        TreeNode *tmpNode = mystack.top();
        mystack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
private:
    stack<TreeNode*> mystack;
    void pushAll(TreeNode *node) {
        while (node) {
            mystack.push(node);
            node = node->left;
        }
    }
};
