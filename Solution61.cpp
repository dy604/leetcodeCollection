
//题目61，Rotate List 旋转链表

class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode *newH = head, *tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        if (k %= len) {
            for (auto i=0; i<len-k; i++)
                tail = tail->next;
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head || !head->next) return head;
        ListNode *fast = head;
        int lens = 1;
        while (k--) {
            if (fast->next) {
                fast = fast->next;
                lens++;
            } else {
                fast = head;
                k %= lens;
            }
        }
        if (fast == head) return head;
        ListNode *slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newHead;
    }
};
