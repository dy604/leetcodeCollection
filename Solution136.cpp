
//题目136，Single Number 单独的数字
//题目137，Single Number II
//题目260，Single Number III

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = nums[0];
        for (int i=1; i<nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        for (int i=1; i<nums.size(); i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        return nums.size()==0 ? 0 : accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};
