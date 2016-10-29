
//与题目2的高地位正好相反

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy(-1);
        ListNode *cur = dummy;
        int carry = 0;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return reverseList(dummy->next);
    }
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head;
        while (cur->next) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        return dummy->next;
    }
};

// Follow up
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n1 = 0, n2 = 0, carry = 0;;
        n1 = getLength(l1);
        n2 = getLength(l2);
        if (n1 > n2) l2 = padList(l2, n1 - n2);
        if (n2 > n1) l1 = padList(l1, n2 - n1);
        ListNode *res = addTwoNumbersDFS(l1, l2, carry);
        if (carry == 1) {
            ListNode *tmp = new ListNode(1);
            tmp->next = res;
            res = tmp;
        }
        return res;
    }
    ListNode *addTwoNumbersDFS(ListNode *l1, ListNode *l2, int &carry) {
        if (!l1 && !l2) return NULL;
        ListNode *list = addTwoNumbersDFS(l1->next, l2->next, carry);
        int sum = l1->val + l2->val + carry;
        ListNode *res = new ListNode(sum % 10);
        res->next = list;
        carry = sum / 10;
        return res;
    }
    ListNode *padList(ListNode *list, int len) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        for (int i = 0; i < len; ++i) {
            cur->next = new ListNode(0);
            cur = cur->next;
        }
        cur->next = list;
        return dummy->next;
    }
    int getLength(ListNode *list) {
        ListNode *cur = list;
        int res = 0;
        while (cur) {
            ++res;
            cur = cur->next;
        }
        return res;
    }
};
