
//题目300，Longest Increasing Subsequence 最长递增子序列

public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] res = new int[nums.length];
        int len = 0;

        for (int i=0; i<nums.length; i++) {
            res[i] = 1;
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    res[i] = Math.max(res[i], res[j]+1);
                }
            }
            len = Math.max(len, res[i]);
        }
        return len;
    }
}

public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0;

        for (int x : nums) {
            int i = Arrays.binary(dp, 0, len, x);
            if (i < 0)
                i = -(i+1);
            dp[i] = x;
            if (i == len)
                len++;
        }
        return len;
    }
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i=0; i<nums.size(); ++i) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = left + (right-left)/2;
                if (dp[mid] < nums[i]) left = mid+1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
        return v.size();
    }
};
