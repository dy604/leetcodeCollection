
//题目117，Populating Next Right Pointers in Each Node II 每个节点的右向指针之二
//题目116，Populating Next Right Pointers in Each Node

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return ;
        TreeLinkNode* p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p;
        if (root->left) root->left->next = root->right ? root->right : p;
        conect(root->left);
        conect(root->right);
    }
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode* cur = q.front();
            q.pop();
            if (cur) {
                cur->next = q.front();
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
            while (p && !p->left && !p->right) p = p->next;
            if (!p) return;
            leftMost = p->left ? p->left : p->right;
            TreeLinkNode *cur = leftMost;
            while (p) {
                if (cur == p->left) {
                    if (p->right) {
                        cur->next = p->right;
                        cur = cur->next;
                    }
                    p = p->next;
                } else if (cur == p->right) {
                    p = p->next;
                } else {
                    if (!p->left && !p->right) {
                        p = p->next;
                        continue;
                    }
                    cur->next = p->left ? p->left : p->right;
                    cur = cur->next;
                }
            }
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (root == nullptr) return;

        TreeLinkNode dummy(-1);
        for (TreeLinkNode *curr=root, *prev=&dummy; curr; curr=curr->next) {
            if (curr->left != nullptr) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != nullptr) {
                prev->next = curr->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        while (root) {
            TreeLinkNode* next = nullptr;
            TreeLinkNode* prev = nullptr;
            for (; root; root=root->next) {
                if (!next) next = root->left ? root->left : root->right;
                if (root->left) {
                    if (root->left) {
                        if (prev) prev->next = root->left;
                        prev = root->left;
                    }
                    if (root->right) {
                        if (prev) prev->next = root->right;
                        prev = root->right;
                    }
                }
                root = next;
            }
        }
    }
};
