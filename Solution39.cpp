
//题目39，Combination Sum 组合之和
//题目40，Combination Sum II
//题目216，Combination Sum III

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        combinationSum(candidates, target, res, cur, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &cur, int begin) {
        if (!target) {
            res.push_back(cur);
            return;
        }
        for (int i=begin; i!=candidates.size() && target>=candidates[i]; ++i) {
            cur.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], res, cur, i);
            cur.pop_back();
        }
    }
};
