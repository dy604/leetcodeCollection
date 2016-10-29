
//题目77，Combinations 组合项

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, k, 1, 0, path, res);
        return res;
    }
private:
    //start表示开始的数。cur表示对现在有的数位进行计数，数位长度达到k位时，将单个组合放入res中
    static void dfs(int n, int k, int start, int cur, vector<int> &path, vector<vector<int>> &res) {
        if (cur == k) {
            res.push_back(path);
        }
        for (int i=start; i<=n; ++i) {
            path.push_back(i);
            dfs(n, k, i+1, cur+1, path, res);
            path.pop_back();
        }
    }
};

class solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> values;
        iota(values.begin(), values.end(), 1);
        vector<bool> select(n, false);
        fill_n(select.begin(), k, true);
        vector<vector<int>> res;
        do {
            vector<int> one(k);
            for (int i=0, index=0; i<n; ++i)
                if (select[i])
                    one[index++] = values[i];
            res.push_back(one);
        } while (prev_permutation(select.begin(), select.end()));
        return res;
    }
};
