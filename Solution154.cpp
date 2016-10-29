
//题目154，Find Minimum in Rotated Sorted Array II 寻找旋转有序数组的最小值之二
//题目153，Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size()-1, res = nums[0];
        while (left < right-1) {
            int mid = left + (right-left)/2;
            if (nums[left] < nums[mid]) {
                res = min(res, nums[left]);
                left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                res = min(res, nums[right]);
                right = mid;
            } else {
                ++left;
            }
        }
        res = min(res, nums[left]);
        res = min(res, nums[right]);
        return res;
    }
};
