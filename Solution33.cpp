
//题目33，Search in Rotated Sorted Array 在旋转有序数组中搜索
//题目81，Search in Rotated Sorted Array II

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int first = 0, last = nums.size();
        while (first != last) {
            const int mid = first + (last-first)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[first] < nums[mid]) {
                if (nums[first]<=target && target<nums[mid])
                    last = mid;
                else
                    first = mid+1;
            } else if (nums[first] > nums[mid]) {
                if (nums[mid]<target && target<=nums[last-1]) {
                    first = mid+1;
                } else {
                    last = mid;
                }
            } else {
                first++;  //处理重复元素
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while (lo < hi) {  //找到旋转点
            int mid = (lo+hi)/2;
            if (nums[mid] > nums[hi]) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        int rot = lo;
        lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int realmid = (mid+rot)%n;
            if (nums[realmid] == target) {
                return realmid;
            }
            if (nums[realmid] < target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return -1;
    }
};
