
//题目34，Search for a Range 搜索一个范围

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        int count = 0;
        int i = 0;
        while (nums[i]<target) {
            i++;
        }
        while (nums[i]==target && i<nums.size()) {
            i++;
            count++;
        }
        if (count == 0) return res;
        res[0] = i-count;
        res[1] = i-1;
        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        int count = 0;
        int start = 0, int end = nums.size()-1;
        while (start < end) {
            int mid = (start+end)/2;
            if (nums[mid] < target)
                start = mid+1;
            else
                end = mid;
        }
        if (nums[start]!=target) {
            return res;
        } else {
            res[0] = start;
        }
        while (nums[start]==target && start<nums.size()) {
            start++;
        }
        res[1] = start-1;
        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        int count = 0;
        int start = 0, end = nums.size()-1;
        while (start < end) {
            int mid = (start+end)/2;
            if (nums[mid]<target)
                start = mid+1;
            else
                end = mid;
        }
        if (nums[start]!=target)
            return res;
        else
            res[0] = start;
        end = nums.size()-1;
        while (start < end) {
            int mid = (start+end)/2+1;
            if (nums[mid]>target)
                end = mid-1;
            else
                start = mid;
        }
        res[1] = end;
        return res;
    }
};
