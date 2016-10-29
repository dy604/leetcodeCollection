
//题目86，Partition List 划分链表

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left_dummy(-1);
        ListNode* right_dummy(-1);

        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;

        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                left_cur->next = cur;
                left_cur = cur;
            } else {
                right_cur->next = cur;
                right_cur = cur;
            }
        }

        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        return left_dummy.next;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (pre->next && pre->next->val<x) pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->val < x) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};
