
//题目81，Search in Rotated Sorted Array II 在旋转有序数组中搜索之二
//题目33，Search in Rotated Sorted Array

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int first = 0;
        int last = nums.size();
        while (first!=last) {
            const int mid = first+(last-first)/2;
            if (nums[mid]==target)
                return true;
            if (nums[first]<nums[mid]) {
                if (nums[first]<=target && target<nums[mid]) {
                    last = mid;
                } else {
                    first = mid+1;
                }
            } else if (nums[first]>nums[mid]) {
                if (nums[mid]<target && target<=nums[last-1]) {
                    first = mid+1;
                } else {
                    last = mid;
                }
            } else {
                first++;
            }

        }
        return false;
    }
};
