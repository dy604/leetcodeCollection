
//题目234，Palindrome Linked List 回文链表

/*思路：
1、遍历整个链表，将链表每个节点的值记录在数组中，再判断数组是不是一个回文数组，时间复杂度为O(n)，但空间复杂度也为O(n)，不满足空间复杂度要求。
2、利用栈先进后出的性质，将链表前半段压入栈中，再逐个弹出与链表后半段比较。时间复杂度O(n)，但仍然需要n/2的栈空间，空间复杂度为O(n)。
3、反转链表法，将链表后半段原地翻转，再将前半段、后半段依次比较，判断是否相等，时间复杂度O(n)，空间复杂度为O(1)满足题目要求。
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != NULL) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow->next = reverseList(slow->next);
            slow = slow->next;
        } else {
            slow = reverseList(slow);
        }
        while (slow) {
            if (head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
