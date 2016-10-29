
//题目27，Remove Element 删除给定数组中的给定元素

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int index = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val)
                nums[index++] = nums[i];
        }
        return index;
    }
};
