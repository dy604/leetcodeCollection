
//题目160，Intersection of Two Linked Lists 求两个链表的交点

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != curB) {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        int lenA = length(headA);
        int lenB = length(headB);
        int count = Math.abs(lenA-lenB);
        while (count > 0) {
            if (lenA > lenB)
                headA = headA.next;
            else
                headB = headB.next;
            count--;
        }
        while (headA!=null && headB!=null) {
            if (headA.val==headB.val) return headA;
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }
    private int length(ListNode head) {
        if (head==null) return 0;
        int lenght = 0;
        while (head!=null) {
            length++;
            head = head.next;
        }
        return length;
    }
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA==null || headB==null) return null;
        int lenA = length(headA);
        int lenB = length(headB);
        while (lenA > lenB) {
            headA = headA.next;
            lenA--;
        }
        while (lenA < lenB) {
            headB = headB.next;
            lenB--;
        }
        while (headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        return headA;
    }
    private int length(ListNode head) {
        if (head == null) return 0;
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }
}
