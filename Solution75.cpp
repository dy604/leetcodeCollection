
//题目75，Sort Colors 颜色排序

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int start = 0;
        int end = nums.size()-1;
        for (int i=0; i<=end; i++) {
            while (nums[i]==2 && i<end)
                swap(nums[i], nums[end--]);
            while (nums[i]==0 && i>start)
                swap(nums[i], nums[start++]);
        }
    }
};

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n0=-1, n1=-1, n2=-1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                nums[++n2] = 2;
                nums[++n1] = 1;
                nums[++n0] = 0;
            } else if (nums[i] == 1) {
                nums[++n2] = 2;
                nums[++n1] = 1;
            } else if (nums[i] == 0) {
                nums[++n2] = 2;
            }
        }
    }
};
