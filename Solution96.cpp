
//题目96，Unique Binary Search Trees 独一无二的二叉搜索树
//题目95，Unique Binary Search Trees II

//动态规划，此题是 Catalan Number卡塔兰数的一个例子。
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            for (int k=1; k<=i; ++k) {
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};
