
//题目62，Unique Paths 不同的路径 题目63，Unique Paths II

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, 1));
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n)
            return uniquePaths(n, m);
        vector<int> pre(m,1);
        vector<int> cur(m,1);

        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                cur[j] = cur[j-1] + pre[j];
            }
            swap(pre,cur);
        }
        return pre[m-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n)
            return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                cur[j] += cur[j-1];
            }
        }
        return cur[m-1];
    }
};

//其实就是机器人总共走m+n-2步，其中m-1步往下走，n-1步往右走，
//本质上就是一个组合问题，也就是从m+n-2个不同元素中每次取出m-1个元素的组合数
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m>n ? n : m;
        for (int i=1; i<=small-1; ++i) {
            num *= m+n-1-i;
            denom *= i;
        }
        return (int)(num/denom);
    }
};
