
//题目109，Convert Sorted List to Binary Search Tree 将有序链表转为二叉搜索树

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        vector<int> tmp;
        while (head) {
            tmp.push_back(head->val);
            head = head->next;
        }
        return sortedArrayTree(tmp, 0, tmp.size()-1);
    }
    TreeNode* sortedArrayTree(vector<int> &arr, int start, int end) {
        if (start > end) return NULL;
        TreeNode* root = new TreeNode(arr[(start+end)/2]);
        root->left = sortedArrayTree(arr, start, (start+end)/2-1);
        root->right = sortedArrayTree(arr, (start+end)/2+1, end);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return rec(head, nullptr);
    }
    TreeNode* rec(ListNode* start, ListNode* end) {
        if (start == end) return nullptr;
        ListNode* p = start, q = start;
        while (q!=end && q->next!=end) {
            p = p->next;
            q = q->next->next;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = rec(start, p);
        root->right = rec(p->next, end);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(listNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p != NULL) {
            n++;
            p = p->next;
        }
        return sortedListToBST(head, n);
    }
    TreeNode* sortedListToBST(ListNode* head, int n) {
        if (head==NULL || n==0) return NULL;
        ListNode* p = head;
        for (int i=1; i<(n+1)/2; ++i) {
            p = p->next;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBST(head, (n+1)/2-1);
        root->right = sortedListToBST(p->next, n-(n+1)/2);
        return root;
    }
};

public class Solution {

    static ListNode currentHead = null;

    public TreeNode sortedListToBST(ListNode head) {
        if(head==null) return null;
        currentHead = head;
        int len = 0;
        while(head!=null){  //获取链表长度
            len++;
            head = head.next;
        }
        return sortedListToBST(0, len-1);
    }

    public TreeNode sortedListToBST(int start, int end){
        if(start>end) return null;

        int mid = start + (end-start)/2;
        TreeNode left = sortedListToBST(start, mid-1); //生成左子树
        TreeNode root = new TreeNode(currentHead.val);
        root.left = left;
        currentHead = currentHead.next;  //链表后移
        root.right = sortedListToBST(mid+1, end);   //生成右子树
        return root;
    }
}
