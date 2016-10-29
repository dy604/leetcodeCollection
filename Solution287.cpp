
//题目287，Find the Duplicate Number 寻找重复数

//不满足空间复杂度要求
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mapping;
        for (int i=0; i<nums.size(); i++) {
            if (++mapping[nums[i]] > 1) {
                return nums[i];
            }
        }
        return 0;
    }
};

//快慢指针找环法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while (low < high) {
            int mid = low + (high-low)/2;
            int cnt = 0;
            for (auto a : nums) {
                if (a <= mid) ++cnt;
            }
            if (cnt <= mid) low = mid+1;
            else high = mid;
        }
        return low;
    }
};
