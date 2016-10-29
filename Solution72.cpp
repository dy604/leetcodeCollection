
//题目72，Edit Distance 编辑距离
//题目161，One Edit Distance(更简单)

//动态规划实现,dp[i][j]表示从word1的前i个字符转换到word2的前j个字符所需要的步骤
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1+1][n2+1];
        for (int i=0; i<=n1; ++i) dp[i][0] = i;
        for (int i=0; i<=n2; ++i) dp[0][i] = i;
        for (int i=1; i<=n1; ++i) {
            for (int j=1; j<=n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};

//动态规划+滚动数组，与动态规划解法一样，只是减少了空间复杂度
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length)
            return minDistance(word2, word1);
        int f[word2.length()+1];
        int upper_left = 0; // 额外用一个变量记录f[i-1][j-1]
        for (int i=0; i<=word2.size(); ++i) f[i] = i;
        for (int i=1; i<=word1.size(); ++i) {
            upper_left = f[0];
            f[0] = i;
            for (int j=1; j<=word2.size(); ++j) {
                int upper = f[j];
                if (word1[i-1] == word2[j-1])
                    f[j] = upper_left;
                else
                    f[j] = 1+min(upper_left, min(f[j], f[j-1]));
                upper_left = upper;
            }
        }
        return f[word2.length()];
    }
};
