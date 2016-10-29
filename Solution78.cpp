
//题目78，Subsets 子集合
//题目90，Subsets II

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        int subm = pow(2, m);
        vector<vector<int>> res(subm, vector<int>());
        for (int i=0; i<m; i++) {
            for (int j=0; j<subm; j++) {
                if ((j>>i) & 1) {
                    res[j].push_back(nums[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1, vector<int>());
        for (int i=0; i<nums.size(); i++) {
            int n = res.size();
            for (int j=0; j<n; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        genSubsets(nums, 0, path, res);
        return res;
    }
    void genSubsets(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(path);
        for (int i=start; i<nums.size(); i++) {
            path.push_back(nums[i]);
            genSubsets(nums, start+1, path, res);
            path.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        genSubsets(nums, 0, path, res);
        return res;
    }
    void genSubsets(vector<int> &nums, int i, vector<int> &path, vector<vector<int>> &res) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }
        res.push_back(nums[i]);
        genSubsets(nums, i+1, path, res);
        res.pop_back();
        genSubsets(nums, i+1, path, res);
        return;
    }
};
