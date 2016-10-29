
//题目143，Reorder List 链表重排序

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head==nullptr || head->next==nullptr) return;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        slow = reverseList(slow);
        ListNode *curr = head;
        while (curr->next) {
            ListNode *tmp = curr->next;
            curr->next = slow;
            slow = slow->next;
            curr->next->next = tmp;
            curr = tmp;
        }
        curr->next = slow;
    }
    ListNode* reverseList(ListNode *head) {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode *prev = head;
        for (ListNode* curr=head->next, *next=curr->next; curr;
            prev=curr, curr=next, next=next?next->next : nullptr) {
            curr->next = prev;
        }
        head->next = nullptr;
        return prev;
    }
};

public class Solution {
    public void reorderList(ListNode head) {
        if(head==null || head.next==null) return;

        //找到链表中间节点
        ListNode p1 = head;
        ListNode p2 = head;
        while(p2.next!=null && p2.next.next!=null){
            p1 = p1.next;
            p2 = p2.next.next;
        }

        //反转中间节点之后的链表
        ListNode preMiddle = p1;
        ListNode preCurrent = p1.next;
        while(preCurrent.next!=null){
            ListNode current = preCurrent.next;
            preCurrent.next = current.next;
            current.next = preMiddle.next;
            preMiddle.next = current;
        }

        //合成两段子链表
        p1 = head;
        p2 = preMiddle.next;
        while(p1!=preMiddle){
            preMiddle.next = p2.next;
            p2.next = p1.next;
            p1.next = p2;
            p1 = p2.next;
            p2 = preMiddle.next;
        }
    }
}
