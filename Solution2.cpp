
//题目2，Add Two Numbers 给定两个链表代表两个数，做两个数相加

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        int carry = 0;

        for (ListNode *pa=l1, *pb=l2; pa!=nullptr || pb!=nullptr;
            pa = pa==nullptr ? nullptr : pa->next,
            pb = pb==nullptr ? nullptr : pb->next,
            cur = cur->next) {
            const int ai = pa==nullptr ? 0 : pa->val;
            const int bi = pb==nullptr ? 0 : pb->val;
            const int val = (ai+bi+carry)%10;
            carry = (ai+bi+carry)/10;
            cur->next = new ListNode(val);
        }

        if (carry > 0) {
            cur->next = new ListNode(carry);
        }
        return dummy.next;
    }
};

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode pa = l1;
        ListNode pb = l2;
        ListNode head = new ListNode(0);
        ListNode cur = head;
        int sum = 0;
        while (pa!=null || pb!=null) {
            sum/10;
            if (pa != null) {
                sum += pa.val;
                pa = pa.next;
            }
            if (pb != null) {
                sum += pb.val;
                pb = pb.next;
            }
            cur.next = new ListNode(sum%10);
            cur = cur.next;
        }

        if (sum/10) {
            cur.next = new ListNode(1);
        }
        return head.next;
    }
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int carry = 0;
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
        return res->next;
    }
};
