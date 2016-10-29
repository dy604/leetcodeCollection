
//题目221，Maximal Square 最大正方形

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<vector<int>> size(m, vector<int>(n, 0));
        int maxsize = 0;
        for (int j=0; j<n; j++) {
            size[0][j] = matrix[0][j] - '0';
            maxsize = max(maxsize, size[0][j]);
        }
        for (int i=1; i<m; i++) {
            size[i][0] = matrix[i][0] - '0';
            maxsize = max(maxsize, size[i][0]);
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == '1') {
                    size[i][j] = min(size[i-1][j-1], min(size[i-1][j], size[i][j-1])) + 1;
                    maxsize = max(maxsize, size[i][j]);
                }
            }
        }
        return maxsize * maxsize;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        int maxsize = 0;
        for (int i=0; i<m; i++) {
            pre[i] = matrix[i][0] - '0';
            maxsize = max(maxsize, pre[i]);
        }
        for (int j=1; j<n; j++) {
            cur[0] = matrix[0][j] - '0';
            maxsize = max(maxsize, cur[0]);
            for (int i=1; i<m; i++) {
                if (matrix[i][j] == '1') {
                    cur[i] = min(cur[i-1], min(pre[i-1], pre[i])) + 1;
                    maxsize = max(maxsize, cur[i]);
                }
            }
            swap(pre, cur);
            fill(cur.begin(), cur.end());
        }
        return maxsize * maxsize;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(m+1, 0);
        int maxsize = 0, pre = 0;
        for (int j=0; j<n; j++) {
            for (int i=1; i<=m; i++) {
                int temp = dp[i];
                if (matrix[i-1][j] == '1') {
                    dp[i] = min(dp[i], min(dp[i-1], pre)) + 1;
                    maxsize = max(maxsize, dp[i]);
                } else dp[i] = 0;
                pre = temp;
            }
        }
        return maxsize * maxsize;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int res = 0;
        for (int i=0; i<matrix.size(); ++i) {
            vector<int> v(matrix[i].size(), 0);
            for (int j=i; j<matrix.size(); ++j) {
                for (int k=0; k<matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = max(res, getSquareArea(v, j-i+1));
            }
        }
        return res;
    }
    int getSquareArea(vector<int> &v, int k) {
        if (v.size() < k) return 0;
        int count = 0;
        for (int i=0; i<v.size(); ++i) {
            if (v[i] != k) count = 0;
            else ++count;
            if (count == k) return k*k;
        }
        return 0;
    }
};
