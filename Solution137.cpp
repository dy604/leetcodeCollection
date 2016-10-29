
//题目137，Single Number II 单独的数字之二
//题目136，Single Number
//题目260，Single Number III

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        const int W = sizeof(int) * 8;
        int count[W];
        fill_n(&count[0], W, 0);
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<W; j++) {
                count[j] += (nums[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int res = 0;
        for (int i=0; i<W; i++) {
            res += (count[i] << i);
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int i=0; i<32; ++i) {
            int sum = 0;
            for (int j=0; j<nums.size(); ++j) {
                sum += (nums[j]>>i) & 1;
            }
            res |= (sum%3) << i;
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int one = 0, two = 0, three = 0;
        for (int i=0; i<nums.size(); ++i) {
            two |= (one & nums[i]);
            one ^= nums[i];
            one &= three;
            two &= three;
        }
        return one;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0, b = 0;
        for (int i=0; i<nums.size(); ++i) {
            b = (b ^ nums[i]) & ~a;
            a = (a ^ nums[i]) & ~b;
        }
        return b;
    }
};
