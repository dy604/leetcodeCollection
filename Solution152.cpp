
//题目152，Maximum Product Subarray 求最大子数组乘积

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = nums[0];
        int maxcur, mincur;

        for (int i=1; i<nums.size(); i++) {
            maxcur = max(max(curMax*nums[i], curMin*nums[i]), nums[i]);
            mincur = min(min(curMax*nums[i], curMin*nums[i]), nums[i]);
            res = max(maxcur, res);
            curMax = maxcur;
            curMin = mincur;
        }
    }
};

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < 0)
                swap(curMax, curMin);
            curMax = max(curMax*nums[i], nums[i]);
            curMin = max(curMin*nums[i], nums[i]);
            res = max(res, curMax);
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        const int n = nums.size();
        int res = INT_MIN;
        int front = 1;
        int back = 1;
        for (int i=0; i<n; i++) {
            front *= nums[i];
            back *= nums[n-i-1];
            res = max(res, max(front, back));
            front = front==0 ? 1 : front;
            back = back==0 ? 1 : back;
        }
        return res;
    }
};
