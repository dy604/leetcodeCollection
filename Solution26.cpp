
//题目26，Remove Duplicates from Sorted Array 从有序数组中删除重复元素
//题目80，Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index+1;
    }
};
