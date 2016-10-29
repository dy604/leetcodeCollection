
//题目209，Minimum Size Subarray Sum 最短子数组之和

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int minimal = INT_MAX;
        int sum = 0, start = 0;
        if (nums.size()==0)
            return 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                minimal = min(minimal, i-start+1);
                sum -= nums[start++];
            }
        }
        return minimal==INT_MAX ? 0 : minimal;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size(), left = 0, right = 0, sum = 0, minlen = INT_MAX;
        while (right < n) {
            do sum += nums[right++];
            while (right<n && sum < s);
            while (left < right && sum - nums[left] >= s)
                sum -= nums[letf++];
            if (sum >= s) minlen = min(minlen, right-left);
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        vector<int> sums = accumulate(nums);
        int n = nums.size(), minlen = INT_MAX;
        for (int i=1; i<=n; i++) {
            if (sums[i] >= s) {
                int p = upper_bound(sums, 0, i, sums[i] - s);
                if (p != -1)
                    minlen = min(minlen, i-p+1);
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
private:
    vector<int> accumulate(vector<int> &nums) {//计算累加值数组
        int n = nums.size();
        vector<int> sums(n+1, 0);
        for (int i=1; i<=n; i++) {
            sums[i] = nums[i-1] + sums[i-1];
        }
        return sums;
    }
    //二分查找差值元素
    int upper_bound(vector<int> &sums, int left, int right, int target) {
        int l = left, r = right;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (sums[m] <= target)
                l = m+1;
            else
                r = m;
        }
        return sums[r] > target ? r : -1;
    }
};
