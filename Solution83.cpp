
//题目83，Remove Duplicates from Sorted List 移除有序链表中的重复项
//题目82，Remove Duplicates from Sorted List II

class Solution {
public:
    ListNode* deleteDuplicate(ListNode* head) {
        if (!head) return head;
        ListNode dummy(head->val+1);
        dummy.next = head;
        recur(&dummy, head);
        return dummy.next;
    }
private:
    static void recur(ListNode* prev, ListNode* cur) {
        if (cur==nullptr) return;
        if (prev->val==cur->val) {
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        } else {
            recur(prev->next, cur->next);
        }
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return nullptr;
        for (ListNode* prev=head, *cur=head->next; cur; cur=cur->next) {
            if (prev->val==cur->val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
        }
        return head;
    }
};
