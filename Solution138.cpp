
//题目138，Copy List with Random Pointer 拷贝带有随机指针的链表

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {};
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (!head) return NULL;
        RandomListNode* res = new RandomListNode(head->label);
        RandomListNode* node = res;
        RandomListNode* cur = head->next;
        map<RandomListNode*, RandomListNode*> m;
        m[head] = res;
        while (cur) {
            RandomListNode* tmp = new RandomListNode(cur->label);
            node->next = tmp;
            m[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        node = res;
        cur = head;
        while (node) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *cur = head;
        while (cur) { //第一步，插入赋值的新节点
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur) { //第二步，拷贝random指针
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        RandomListNode *res = head->next;
        while (cur) { //第三部，断开原链表与新链表之间的关系
            RandomListNode *tmp = cur->next;
            cur->next = tmp->next;
            if (tmp->next) tmp->next = tmp->next->next;
            cur = cur->next;
        }
        return res;
    }
};
