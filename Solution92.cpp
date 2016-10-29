
//题目92，Reverse Linked List II 倒置链表之二
//题目206，Reverse Linked List

class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i=0; i<m-1; i++)
            prev = prev->next;
        ListNode *const head2 = prev;
        prev = prev->next;
        ListNode *cur = prev->next;
        for (int i=m; i<n; i++) {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }
        return dummy.next;
    }
};
