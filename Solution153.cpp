
//题目153，Find Minimum in Rotated Sorted Array 寻找旋转有序数组的最小值
//题目154，Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int> &nums) {
        int first = 0;
        int last = nums.size()-1;
        while (first < last) {
            if (nums[first] < nums[last])
                return nums[first];
            int mid = (first + last)/2;
            if (nums[first]<=nums[mid]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return nums[first];
    }
};

class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size()-1, mid;
        while (nums[start] > nums[end]) {
            mid = (start+end)/2;
            if (nums[mid] > nums[start])
                start = mid + 1;
            else {
                ++start;
                end = mid;
            }
        }
        return nums[start];
    }
};
