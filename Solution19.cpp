
//��Ŀ19��Remove Nth Node From End of List��ɾ����������N���ڵ�

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy, *cur = &dummy;
        while (n) {
            pre = pre->next;
            n--;
        }
        while (pre->next) {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head->next) return NULL;
        ListNode *pre = head, *cur = head;
        for (int i=0; i<n; i++) cur = cur->next;
        if (!cur) return head->next;
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
