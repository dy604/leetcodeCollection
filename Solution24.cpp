
//题目24，Swap Nodes in Pairs 成对交换节点

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        if (head==nullptr || head->next==nullptr)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        for (ListNode *prev=&dummy, *cur=prev->next, *next=cur->next; next; prev=cur, cur=cur->next, next=cur?cur->next : nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *p = head;
        while (p && p->next) {
            swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *t = head->next;
        head->next =  swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};
