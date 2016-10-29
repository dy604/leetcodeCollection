
//题目46，Permutations 全排列

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (nextPermutation(nums));
    }
    bool nextPermutation(vector<int> &nums) {
        int k = -1;
        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            return false;
        }
        int l = -1;
        for (int i=nums.size()-1; i>k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, path, res);
        return res;
    }
    void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (auto i : nums) {
            auto pos = find(path.begin(), path.end(), i);
            if (pos == nums.end()) {
                path.push_back(i);
                dfs(nums, path, res);
                path.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        permuteDFS(nums, 0, res);
        return res;
    }
    void permuteDFS(vector<int> &nums, int start, vector<vector<int>> &res) {
        if (start >= nums.size()) res.push_back(nums);
        for (int i=start; i<nums.size(); ++i) {
            swap(nums[start], nums[i]);
            permuteDFS(nums, start+1, res);
            swap(nums[start], nums[i]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.empty()) return vector<vector<int>>(1, vector<int>());
        vector<vector<int>> res;
        int first = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> words = permute(nums);
        for (auto &a : words) {
            for (int i=0; i<=a.size(); ++i) {
                a.insert(a.begin()+i, first);
                res.push_back(a);
                a.erase(a.begin()+i);
            }
        }
        return res;
    }
};
