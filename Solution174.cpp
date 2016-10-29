
//题目174，Dungeon Game 地牢游戏

//动态规划
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m][n];
        dp[m-1][n-1] = max(1, 1-dungeon[m-1][n-1]);//初始化公主房间所需的能量
        for (int i=m-2; i>=0; --i) {
            dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);//计算公主所在那一列
        }
        for (int j=n-2; j>=0; --j) {
            dp[m-1][j] = max(1, dp[m-1][j+1] - dungeon[m-1][j]);//计算公主所在那一行
        }
        for (int i=m-2; i>=0; --i) {//计算一般情况，直到走到骑士的位置
            for (int j=n-2; j>=0; --j) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
