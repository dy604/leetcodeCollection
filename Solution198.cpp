
//题目198，House Robber 打家劫舍
//题目213，House Robber II

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i=2; i<nums.size(); ++i) {
            dp.push_back(max(nums[i]+dp[i-2], dp[i-1]));
        }
        return dp.back();
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        int take = 0, noTake = 0;
        for (int i=0; i<nums.size(); ++i) {
            int temp = take;
            take = noTake + nums[i];
            noTake = max(temp, noTake);
        }
        return max(take, noTake);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int even = 0, odd = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (i%2 == 0) {
                even += nums[i];
                even = max(even, odd);
            } else {
                odd += nums[i];
                odd = max(even, odd);
            }
        }
        return max(even, odd);
    }
};
