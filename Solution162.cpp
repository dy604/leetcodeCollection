
//题目162，Find Peak Element 求数组的峰值

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int peakIndex = 0;
        int n = nums.size();
        for (int i=1; i<n-1; i++) {
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
                if (nums[i]>nums[peakIndex]) {
                    peakIndex = i;
                }
            }
        }
        if (nums[n-1]>nums[peakIndex]) {
            peakIndex = n-1;
        }
        return peakIndex;
    }
};

//可能包含多个峰值元素，如果是这种情况，返回任何一个峰值元素下标即可。
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                return i-1;
            }
        }
        return nums.size()-1;
    }
};

//迭代+二分查找
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        return backtracking(nums, 0, nums.size()-1);
    }
    int backtracking(vector<int> &nums, int low, int high) {
        if (low == high) {
            return low;
        } else {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if (nums[mid1]>nums[mid2]) {
                return backtracking(nums, low, mid1);
            } else {
                return backtracking(nums, mid2, high);
            }
        }
    }
};

//采用二分查找的方法；
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            int mid1 = (low+high)/2;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2]) {
                low = mid2;
            } else {
                high = mid1;
            }
        }
        return low;
    }
};
