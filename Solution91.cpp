
//题目91，Decode Ways 解码方法

public class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0) return 0;
        int[] S = new int[s.length()];
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i) == '0') {
                if (i==0 || s.charAt(i-1)=='0' || s.charAt(i-1)>'2')
                    return 0;
                else
                    S[i] = i>1 ? S[i-2] : 1;
            } else {
                if (1>0 && (s.charAt(i-1)=='1' || s.charAt(i-1)=='2' && s.charAt(i)<'7')) {
                    S[i] = S[i-1] + (i>1 ? S[i-2] : 1);
                } else {
                    S[i] = i > 0 ? S[i-1] : 1;
                }
            }
        }
        return S[s.length()-1];
    }
}

public class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0) return s.length();
        int[] dp = new int[s.length()+1];
        dp[0] = 1;
        dp[1] = s.charAt(0) == '0' ? 0 : 1;
        for (int i=2; i<=s.length(); i++) {
            if (Integer.parseInt(s.substring(i-2, i)) <= 26 && Integer.parseInt(s.substring(i-2, i))>10) {
                dp[i] += dp[i-2];
            }
            if (Integer.parseInt(s.substring(i-1, i)) != 0) {
                dp[i] += dp[i-1];
            }
        }
        return dp[s.length()];
    }
}

public class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        if (n == 0) return 0;
        int[] memo = new int[n+1];
        memo[n] = 1;
        memo[n-1] = s.charAt(n-1) != '0' ? 1 : 0;
        for (int i=2; i>=0; i--) {
            if (s.charAt(i) == '0')
                continue;
            else
                memo[i] = (Integer.parseInt(s.substring(i, i+2))<26) ? memo[i+1]+memo[i+2] : memo[i+1];
        }
        return memo[0];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n+2, 1);
        for (int i=2; i<n+2; ++i) {
            if (s[i-2] == '0') dp[i] = 0;
            else dp[i] = dp[i-1];
            if (i-3>=0 && (s[i-3]=='1' || (s[i-3]=='2' && s[i-2]<='6'))) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n+1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i=1; i<dp.size(); ++i) {
            if (s[i-1]!='0') dp[i] += dp[i-1];
            if (i>=2 && s.substr(i-2, 2)<="26" && s.substr(i-2,2)>="10") {
                dp[i] += dp[i-2];
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front()=='0') return 0;
        int c1 = 1, c2 = 1;
        if (s[i-1] == '1' || (s[i-1] == '2' && s[i]<='6')) {
            c1 = c1 + c2;
            c2 = c1 - c1;
        } else {
            c2 = c1;
        }
        return c1;
    }
};
