
//题目45，Jump Game II 跳跃游戏之二 题目55，Jump Game

class Solution {
public:
    int jump(vector<int> &nums) {
        int res = 0, i = 0, cur = 0;
        while (cur < nums.size()-1) {
            int pre = cur;
            while (i <= pre) {
                cur = max(cur, i+nums[i]);
                ++i;
            }
            ++res;
            if (pre == cur) return -1;
        }
        return res;
    }
};

class Solution {
public:
    int jump(vector<int> &nums) {
        int res = 0, last = 0, cur = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i > last) {
                last = cur;
                ++res;
                if (cur >= nums.size()-1) break;
            }
            cur = max(cur, i+nums[i]);
        }
        return res;
    }
};
