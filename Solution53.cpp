
//题目53，Maximum Subarray 最大子数组

//动态规划
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int curMax = nums[0];
        int res = nums[0];
        for (int i=1; i<nums.size(); i++) {
            curMax = max(curMax+nums[i], nums[i]);
            res = max(res, curMax);
        }
        return res;
    }
};

//分治法
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        return getMaxSubArray(nums, 0, nums.size()-1);
    }
    int getMaxSubArray(vector<int> &nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = (left+right)/2;
        int lmax = getMaxSubArray(nums, left, mid-1);
        int rmax = getMaxSubArray(nums, mid+1, right);
        int mmax = nums[mid], tmp = nums[mid];
        for (int i=mid-1; i>=left; --i) {
            tmp += nums[i];
            mmax = max(mmax, tmp);
        }
        tmp = mmax;
        for (int i=mid+1; i<=right; ++i) {
            tmp += nums[i];
            mmax = max(mmax, tmp);
        }
        return max(mmax, max(lmax, rmax));
    }
};
