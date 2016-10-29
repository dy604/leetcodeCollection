
//题目148，Sort List 链表排序

//归并排序
class Solution {
public:
    ListNode* sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortList(head);
        slow = sortList(slow);
        return merge(fast, slow);
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head;
                head1 = head1->next;
            } else {
                cur->next = head;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1) cur->next = head1;
        if (head2) cur->next = head2;
        return res->next;
    }
};

