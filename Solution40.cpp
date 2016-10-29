
//题目40，Combination Sum II 组合之和之二
//题目39，Combination Sum
//题目216，Combination Sum III

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        combinationSum2(candidates, res, cur, target, 0);
        return res;
    }
    void combinationSum2(vector<int> &candidates, vector<vector<int>> &res, vector<int> &cur, int target, int start) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0)
            return;
        for (int i=start; i<candidates.size(); i++) {
            if (i>start && candidates[i]==candidates[i-1])
                continue;
            cur.push_back(candidates[i]);
            combinationSum2(candidates, res, cur, target-candidates[i], i+1);
            cur.pop_back();
        }
    }
};
