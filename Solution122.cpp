
//题目122，Best Time to Buy and Sell Stock II 买股票的最佳时间之二
//题目121，Best Time to Buy and Sell Stock
//题目123，Best Time to Buy and Sell Stock III
//题目188，Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};
