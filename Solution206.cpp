
//题目206，Reverse Linked List 倒置链表

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseList(head, nullptr);
    }
private:
    ListNode* reverseList(ListNode* head, ListNode* newhead) {
        if (head == nullptr) {
            return newhead;
        }
        ListNode *next = head->next;
        head->next = newhead;
        return reverseList(next, head);
    }
};
