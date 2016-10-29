
//题目213，House Robber II 打家劫舍之二
//题目198，House Robber

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        if (right-left<=1) return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left+1] = max(nums[left], nums[left+1]);
        for (int i=left+2; i<right; ++i) {
            dp[i] = max(nums[nums[i]+dp[i-2], dp[i-1]);
        }
        return dp.back();
    }
};

class solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size()<=1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        int take = 0, noTake = 0;
        for (int i=left; i<right; ++i) {
            int temp = take;
            take = noTake + nums[i];
            noTake = max(temp, noTake);
        }
        return max(take, noTake);
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> v1 = nums, v2 = nums;
        v1.erase(v1.begin());
        v2.pop_back();
        return max(rob_house(v1), rob_house(v2));
    }
    int rob_house(vector<int> &nums) {
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
