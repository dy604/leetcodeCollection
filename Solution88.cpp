
//题目88，Merge Sorted Array 混合插入有序数组

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while (i>-1 && j>-1) {
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }

        while (j>-1) {
            nums1[k--] = nums2[j--];
        }
    }
};
