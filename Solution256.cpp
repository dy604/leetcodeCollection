
//题目256，Paint House 粉刷房子
//题目265，Paint House II

//动态规划，dp[i][j]表示刷到第i+1房子用颜色j的最小花费
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        for (int i=1; i<dp.size(); ++i) {
            for (int j=0; j<3; ++j) {
                dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        for (int i=1; i<dp.size(); ++i) {
            dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};
