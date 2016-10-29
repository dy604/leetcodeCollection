
//题目279，Perfect Squares 完全平方数

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        vector<int> cntPerfectSquares(n+1, INT_MAX);
        cntPerfectSquares[0] = 0;

        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                cntPerfectSquares[i] = min(cntPerfectSquares[i], cntPerfectSquares[i-j*j]+1);
            }
        }

        return cntPerfectSquares.back();
    }
};

public class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        // 将所有非平方数的结果置最大，保证之后比较的时候不被选中
        Arrays.fill(dp, Integer.MAX_VALUE);
        // 将所有平方数的结果置1
        for(int i = 0; i * i <= n; i++){
            dp[i * i] = 1;
        }
        // 从小到大找任意数a
        for(int a = 0; a <= n; a++){
            // 从小到大找平方数bｘb
            for(int b = 0; a + b * b <= n; b++){
                // 因为a+b*b可能本身就是平方数，所以我们要取两个中较小的
                dp[a + b * b] = Math.min(dp[a] + 1, dp[a + b * b]);
            }
        }
        return dp[n];
    }
}


class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;

        static vector<int> cntPerfectSquares({0});

        while(cntPerfectSquares.size()<=n){
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for(int i=1; i*i<=m; i++){
                cntSquares = min(cntSquares, cntPerfectSquares[m-i*i] + 1);
            }
            cntPerfectSquares.push_back(cntSquares);
        }
        return cntPerfectSquares[n];
    }
};
