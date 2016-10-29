
//题目283，Move Zeroes 移动零

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0, j=0; i<nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
            ++right;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int index = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for (; index < nums.size(); index++) {
            nums[i] = 0;
        }
    }
};
