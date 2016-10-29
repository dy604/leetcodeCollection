
//题目41，First Missing Positive 首个缺失的正数

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.size() < 1) return 1;
        unordered_map<int, int> m;
        int mx = nums[0];
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) {
                m[nums[i]] = 1;
                mx = max(mx, nums[i]);
            }
        }
        for (int i=1; i<=mx; ++i) {
            if (m.find(i) == m.end()) return i;
        }
        return mx+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.size() < 1) return 1;
        unordered_map<int, int> m;
        int mx = nums[0];
        for (int num : nums) {
            ++m[num];
            mx = max(mx, num);
        }
        for (int i=1; i<=mx; ++i) {
            if (m.find(i) == m.end()) return i;
        }
        return mx+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i]!=i+1 && nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } else {
                i++;
            }
        }
        for (i=0; i<n; ++i) {
            if (nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i=0; i<nums.size(); i++) {
            if (i+1==nums[i]) continue;
            while (nums[i]>=1 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};
