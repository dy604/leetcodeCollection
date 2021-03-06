
//题目97，Interleaving String 交织相错的字符串

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for (int i=1; i<=n1; ++i) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for (int i=1; i<=n2; ++j) {
            dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        for (int i=1; i<=n1; ++i) {
            for (int j=1; j<=n2; ++j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i-1+j]) || (dp[i][j-1]&&s2[j-1]==s3[j-1+i]);
            }
        }
        return dp[n1][n2];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length()!=s1.length()+s2.length())
            return false;
        bool table[s1.length()+1][s2.length()+1];
        for (int i=0; i<s1.length()+1; i++) {
            for (int j=0; j<s2.length()+1; j++) {
                if (i==0 && j==0)
                    table[i][j] = true;
                else if (i == 0)
                    table[i][j] = (table[i][j-1] && s2[j-1]==s3[i+j-1]);
                else if (j == 0)
                    table[i][j] = (table[i-1][j] && s1[i-1]==s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1]==s3[i+j-1]) || (table[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return table[s1.length()][s2.length()];
    }
};
