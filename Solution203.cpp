
//题目203，Remove Linked List Elements 移除链表元素

//递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val==val ? head->next : head;
    }
};

//迭代
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head;
        ListNode *pre = &dummy;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
