
//题目216，Combination Sum III 组合之和之三
//题目39，Combination Sum
//题目40，Combination Sum II

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        combinationSum3(res, cur, k, n);
        return res;
    }
private:
    void combinationSum3(vector<vector<int>> &res, vector<int> &cur, int k, int n) {
        if (n==0 && cur.size()==k) {
            res.push_back(cur);
            return;
        }
        if (cur.size() < k) {
            for (int i = cur.size()==0 ? 1 : cur.back()+1; i<=9; ++i) {
                if (n - i < 0)
                    break;
                cur.push_back(i);
                combinationSum3(res, cur, k, n-i);
                cur.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, 1, k, n);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &path, int start, int k, int target) {
        if (target==0 && k==0) {
            res.push_back(path);
            return ;
        }
        for (int i=start; i<=10-k && i<=target; i++) {
            path.push_back(i);
            backtrack(res, path, i+1, k-1, target-i);
            path.pop_back();
        }
    }
};
