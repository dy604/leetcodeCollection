
//题目32，Longest Valid Parentheses 最长有效括号

class Solution {
public:
    int longestParentheses(string s) {
        int res = 0, start = 0;
        stack<int> m;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') m.push(i);
            else if (s[i] == ')') {
                if (m.empty()) start = i+1;
                else {
                    m.pop();
                    res = m.empty() ? max(res, i-start+1) : max(res, i-m.top());
                }
            }
        }
        return res;
    }
};

//动态规划
class Solution {
public:
    int longestParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int ret = 0;
        for (int i=s.size()-2; i>=0; --i) {
            int match = i+dp[i+1]+1;
            if (s[i]=='(' && match<s.size() && s[match]==')') {
                dp[i] = dp[i+1] + 2;
                if (match+1 < s.size()) dp[i] += dp[match+1];
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
