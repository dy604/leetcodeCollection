
//题目35，Search Insert Position 搜索插入位置

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]>=target)
                return i;
        }
        return nums.size();
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while (start < end) {
            int mid = (start+end)/2;
            if (nums[mid] < target)
                start = mid+1;
            else
                end = mid;
        }
        if (nums[start]>=target)
            return start;
        else
            return start+1;
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
    }
};
