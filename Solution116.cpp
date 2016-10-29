
//题目116，Populating Next Right Pointers in Each Node 每个节点的右向指针
//题目117，Populating Next Right Pointers in Each Node II

struct TreeLinkNode {
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        if (root->left) root->left->next = root->right;
        if (root->right) root->right->next = root->next ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
    }
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        connect(root, NULL);
    }
private:
    void connect(TreeLinkNode* root, TreeLinkNode* sibling) {
        if (root == nullptr)
            return;
        else
            root->next = sibling;
        connect(root->left, root->right);
        if (sibling)
            connect(root->right, sibling);
        else
            connect(root->right, nullptr);
    }
};

class solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode *cur = q.front();
            q.pop();
            if (cur) {
                cur->next = q.front;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
                if (q.size()==0 || q.front()==NULL) return;
                q.push(NULL);
            }
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        TreeLinkNode* leftMost = root;
        while (leftMost) {
            TreeLinkNode* p = leftMost;
            if (!p->left) return;
            leftMost = p->left;
            TreeLinkNode* cur = leftMost;
            while (p) {
                if (cur == p->left) {
                    cur->next = p->right;
                    cur = cur->next;
                    p = p->next;
                } else {
                    cur->next = p->left;
                    cur = cur->next;
                }
            }
        }
    }
};
