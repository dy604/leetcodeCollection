
//题目108，Convert Sorted Array to Binary Search Tree 将有序数组转为二叉搜索树

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, right);
        return root;
    }
};

public class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        int len = nums.length;
        if (len == 0) return null;
        TreeNode head = new TreeNode(0);
        Deque<TreeNode> nodeStack       = new LinkedList<TreeNode>() {{ push(head);  }};
        Deque<Integer>  leftIndexStack  = new LinkedList<Integer>()  {{ push(0);     }};
        Deque<Integer>  rightIndexStack = new LinkedList<Integer>()  {{ push(len-1); }};

        while (!nodeStack.isEmpty()) {
            TreeNode currNode = nodeStack.pop();
            int left = leftIndexStack.pop();
            int right = rightIndexStack.pop();
            int mid = left + (right - left)/2;
            currNode.val = nums[mid];
            if (left <= mid-1) {
                currNode.left = new TreeNode(0);
                nodeStack.push(currNode.left);
                leftIndexStack.push(left);
                rightIndexStack.push(mid-1);
            }
            if (mid+1 <= right) {
                currNode.right = new TreeNode(0);
                nodeStack.push(currNode.right);
                leftIndexStack.push(mid+1);
                rightIndexStack.push(right);
            }
        }
        return head;
    }
}
