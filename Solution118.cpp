
//题目118，Pascal's Triangle 杨辉三角
//题目119，Pascal's Triangle II

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i=0; i<numRows; i++) {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;

            for (int j=1; j<i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (auto i=0; i<numRows; ++i) {
            res.push_back(vector<int>(i+1, 1));
            for (auto j=1; j<i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
