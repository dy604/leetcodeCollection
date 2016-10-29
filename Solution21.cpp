
//题目21，Merge Two Sorted Lists，合并两个有序的混合链表

class Solution {
public: //递归实现
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1==nullptr) return l2;
        if (l2==nullptr) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution {
public: //迭代实现
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
