
//题目188，Best Time to Buy and Sell Stock IV 买卖股票的最佳时间之四
//题目121，Best Time to Buy and Sell Stock
//题目122，Best Time to Buy and Sell Stock II
//题目123，Best Time to Buy and Sell Stock III

//定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
//定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveMaxProfit(prices);
        int g[k+1] = {0};
        int l[k+1] = {0};
        for (int i=0; i<prices.size()-1; ++i) {
            int diff = prices[i+1] - prices[i];
            for (int j=k; j>=1; --j) {
                l[j] = max(g[j-1] + max(diff,0), l[j]+diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i=1; i<prices.size(); ++i) {
            if (prices[i] - prices[i-1] > 0) {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
