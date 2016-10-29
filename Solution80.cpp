
//题目80，Remove Duplicates from Sorted Array II
//题目26，Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int index = 0, count = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[index] != nums[i]) {
                nums[++index] = nums[i];
                count = 0;
            } else if (nums[index]==nums[i] && count<1) {
                nums[++index] = nums[i];
                count++;
            }
        }
        return index+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size(), count = 0;
        for (int i=2; i<n; i++) {
            if (nums[i]==nums[i-2-count]) {
                count++;
            } else {
                nums[i-count] = nums[i];
            }
        }
        return n-count;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (int n : nums) {
            if (i<2 || n>nums[i-2])
                nums[i++] = n;
        }
        return i;
    }
};
