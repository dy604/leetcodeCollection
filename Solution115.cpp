
//题目115，Distinct Subsequences 不同的子序列

//动态规划，递推公式为，dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0)
class Solution {
public:
    int numDistinct(string s, string t) {
        int dp[t.size()+1][s.size()+1];
        for (int i=0; i<=s.size(); ++i) dp[0][i] = 1;
        for (int i=1; i<=t.size(); ++i) dp[i][0] = 0;
        for (int i=1; i<=t.size(); ++i) {
            for (int j=1; j<=s.size(); ++j) {
                dp[i][j] = dp[i][j-1] + (t[i-1]==s[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[t.size()][s.size()];
    }
};

//设状态为f(i; j)，表示T[0,j] 在S[0,i] 里出现的次数
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> f(t.size() + 1);
        f[0] = 1;
        for (int i=0; i<s.size(); ++i) {
            for (int j=t.size()-1; j>=0; --j) {
                f[j+1] += s[i]==t[j] ? f[j] : 0;
            }
        }
        return f[t.size()];
    }
};
