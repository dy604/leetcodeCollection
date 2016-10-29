
//题目222，Count Complete Tree Nodes 求完全二叉树的节点个数

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        //height记录树深，sum计数完全二叉树节点数量, i循环计数
        int height = 0, sum = 0, i = 0;
        TreeNode *t = root, *t0 = NULL;
        while (t) {//得到完全二叉树深
            t = t->left;
            height++;
        }
        t = root;
        int level = height - 2;
        while (level > -1) {//获取到最下面两层的节点数量
            t0 = t->left;
            for (i=0; i<level; ++i) {//将节点指针移到最底层
                t0 = t0->right;
            }
            if (t0) {//最右t0节点不为空，则继续往右执行
                sum += 1<<level;
                t = t->left;
            } else {//否则往左执行左节点部分
                t = t->left;
            }
            level--;//继续下一层
        }
        if (t)//如果是完全二叉树，加上最后一个最右边的节点数
            sum++;
        return sum + ((1<<(height-1))-1);
    }
};

//简单
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int l = lheight(root->left), r = lheight(root->right);
        if (l > r)
            return countNodes(root->left) + (1<<r);
        else
            return countNodes(root->right) + (1<<l);
    }
private:
    int lheight(TreeNode* root) {
        int depth = 0;
        while (root) {
            root = root->left;
            depth++;
        }
        return depth;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lCount = 0, rCount = 0;
        for (TreeNode* l = root->left; l; l = l->left) {
            lCount++;
        }
        for (TreeNode* r = root->right; r; r = r->left) {
            rCount++;
        }
        if (lCount > rCount)
            return countNodes(root->left) + (1<<rCount);
        else
            return countNodes(root->right) + (1<<lCount);
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int sum = 0, lCount = 0, rCount = 0;
        while (root) {
            lcount = 0, rCount = 0;
            for (TreeNode* l = root->left; l; l = l->left)
                lCount++;
            for (TreeNode* r = root->right; r; r = r->left)
                rCount++;
            if (lCount > rCount) {
                root = root->left;
                sum += (1<<rCount);
            } else {
                root = root->right;
                sum += (1<<lCount);
            }
        }
        return sum;
    }
};
