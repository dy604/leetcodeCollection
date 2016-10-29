
//题目132，Palindrome Partitioning II 拆分回文串之二
//题目131，Palindrome Partitioning

class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        int f[n+1];
        bool P[n][n];
        fill_n(&P[0][0], n*n, false); //初始化二维数组
        //最坏的情况下是每个字符都要分隔开
        for (int i=0; i<=n; i++)
            f[i] = n-1-i;
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                if (s[i]==s[j] && (j-i<2 || P[i+1][j-1])) {
                    P[i][j] = true;
                    f[i] = min(f[i], f[j+1]+1);
                }
            }
        }
        return f[0];
    }
};

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        bool P[len][len]; //判断是否是回文串的动态规划数组
        int dp[len+1];  //分隔动态规划数组
        for (int i=0; i<=len; ++i)
            dp[i] = len-i-1; // 最后一个f[n]=-1
        for (int i=0; i<len; ++i) { //初始化回文动态规划数组
            for (int j=0; j<len; ++j) {
                P[i][j] = false;
            }
        }
        for (int i=len-1; i>=0; --i) {
            for (int j=i; j<len; ++j) {
                //P[i][j] = s[i]==s[j] && P[i+1][j-1]是判断是否是回文串的状态转移方程
                if (s[i]==s[j] && (j-i<=1 || P[i+1][j-1])) {
                    P[i][j] = true; //说明从i到j处是回文串
                    dp[i] = min(dp[i], dp[j+1]+1); //最小cut数的状态转移方程
                }
            }
        }
        return dp[0];
    }
};
