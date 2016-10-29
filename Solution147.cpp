
//题目147，Insertion Sort List 链表插入排序

class Solution {
public:
    LisNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head;
        ListNode *prev = dummy;
        ListNode *next = NULL;
        while (cur) {
            next = cur->next;
            if (!prev || !prev->next || prev->next->val>=cur->val) prev = dummy;
            while (prev->next && prev->next->val<cur->val) {
                prev = prev->next;
            }
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode dummy(-1);
        while (head) {
            ListNode *iter = &dummy;
            while(iter->next && iter->next->val < head->val)
                iter = iter->next;
            ListNode *next = head->next;
            head->next = iter->next;
            iter->next = head;
            head = next;
        }
        return dummy.next;
    }
};
