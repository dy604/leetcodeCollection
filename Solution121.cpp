
//题目121，Best Time to Buy and Sell Stock 买卖股票的最佳时间
//题目122，Best Time to Buy and Sell Stock II
//题目123，Best Time to Buy and Sell Stock III
//题目188，Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()<2)
            return 0;
        int curMin = prices[0];
        int maxProfit = 0;
        for (int i=0; i<prices.size(); i++) {
            curMin = min(curMin, prices[i]);
            maxProfit = max(maxProfit, prices[i]-curMin);
        }
        return maxProfit;
    }
};
