
//题目237，Delete Node in a Linked List 删除链表的节点

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};
