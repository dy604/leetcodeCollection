
//题目23，Merge k Sorted Lists 合并k个有序链表

class Solution {
public:
    ListNode* mergeLists(vector<ListNode*> lists) {
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n+1)/2;
            for (int i=0; i<n/2; i++) {
                lists[i] = mergelists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
    ListNode* mergelists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            if (l1) cur->next = l1;
            if (l2) cur->next = l2;
        }
        return head->next;
    }
};

class Solution {
public:
    ListNode* mergeLists(vector<ListNode*> lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i=0; i<lists.size(); ++i) {
            if (lists[i]) q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }
};
