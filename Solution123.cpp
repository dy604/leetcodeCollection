
//题目123，Best Time to Buy and Sell Stock III 买股票的最佳时间之三
//题目121，Best Time to Buy and Sell Stock
//题目122，Best Time to Buy and Sell Stock II
//题目188，Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i=0; i<prices.size()-1; ++i) {
            int diff = prices[i+1] - prices[i];
            for (int j=2; j>=1; --j) {
                l[j] = max(g[j-1] + max(diff, 0), l[j]+diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        const int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for (int i=1, valley=prices[0]; i<n; ++i) {
            valley = min(valley, prices[i]);
            f[i] = max(f[i-1], prices[i]-valley);
        }

        for (int i=n-2, peak=prices[n-1]; i>=0; --i) {
            peak = max(peak, prices[i]);
            g[i] = max(g[i], peak-prices[i]);
        }

        int max_profit = 0;
        for (int i=0; i<n; ++i)
            max_profit = max(max_profit, f[i]+g[i]);

        return max_profit;
    }
};
