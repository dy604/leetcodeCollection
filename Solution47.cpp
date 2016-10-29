
//题目47，Permutations II 全排列2

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<int> visited;
        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int> &nums, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> &res) {
        if (level >= nums.size()) res.push_back(out);
        else {
            for (int i=0; i<nums.size(); i++) {
                if (visited[i] == 0) {
                    if (i>0 && nums[i]==nums[i-1] && nums[i-1]==0) continue;
                    visited[i] = 1;
                    out.push_back(nums[i]);
                    permuteUniqueDFS(nums, level+1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i=start; i<nums.size(); i++) {
            if (i!=start && nums[i]==nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    }
};
