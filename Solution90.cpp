
//题目90，Subsets II 子集合之二
//题目78，Subsets

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res(1, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ) {
            int count = 0;
            while (i+count<nums.size() && nums[i+count]==nums[i])
                count++;
            int preN = res.size();
            for (int j=0; j<preN; j++) {
                vector<int> cur = res[j];
                for (int k=0; k<count; k++) {
                    cur.push_back(nums[i]);
                    res.push_back(cur);
                }
            }
            i += count;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res(1, vector<int>());
        sort(nums.begin(), nums.end());

        int size = 0;
        int startIndex = 0;
        for (int i=0; i<nums.size(); i++) {
            startIndex = (i>1 && (nums[i]==nums[i-1]) ? size : 0);
            size = res.size();
            for (int i=startIndex; i<size; j++) {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> pre;
        res.push_back(pre);
        dfs(res, pre, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &pre, vector<int> &nums, int k) {
        if (k >= nums.size()) return ;
        for (int i=k; i<nums.size(); i++) {
            if (nums[i]!=nums[i-1] || i==k) {
                pre.push_back(nums[i]);
                res.push_back(pre);
                dfs(res, pre, nums, i+1);
                pre.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        f(nums, res, 0, temp);
        return res;
    }
    void f(vector<int> &nums, vector<vector<int>> &res, int i, vector<int> &temp) {
        if (i == nums.size()) {
            res.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        int j = i + 1;
        f(nums, res, j, temp);
        temp.pop_back();
        while (j<nums.size() && nums[j]==nums[i]) {j++;}
        f(nums, res, j, temp);
        return;
    }
};
