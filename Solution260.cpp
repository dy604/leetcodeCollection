
//题目260，Single Number III 单独的数字之三
//题目136，Single Number
//题目137，Single Number II

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //将nums数组中所有数字取异或操作，得到两个不同数字异或的结果
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff; //获得最右端为1的位，因为是异或结果，所以可以通过该位将两个不相同的数分到不同的小组
        vector<int> res(2, 0);
        for (auto &a : nums) {
            if (a & diff)
                res[0] ^= a;
            else
                res[1] ^= a;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //将nums数组中所有数字取异或操作，得到两个不相同数字异或的结果
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        //获得最右端为1的位，因为是异或结果，所以可以通过该位将两个不相同的数分到不同小组
        int lowestOneBit = diff & (~(diff - 1)); //等效diff &= -diff;
        vector<int> res(2, 0);
        for (auto &a : nums) {
            if (a & lowestOneBit)//利用得到的位将nums数组分成两个小组，采用Single Number的算法实现
                res[0] ^= a;
        }
        res[1] = res[0] ^ diff;
        return res;
    }
};
