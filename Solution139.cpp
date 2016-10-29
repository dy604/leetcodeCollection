
//题目139，Word Break 拆分词句

//动态规划，res[i]是表示到字符串s的第i个元素为止能不能用字典中的词来表示
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        vector<bool> res(len+1, false);
        res[0] = true;
        for (int i=0; i<len+1; i++) {
            for (int j=0; j<i; j++) {
                if (res[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end()) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[len];
    }
};

//较好
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.length() < 1) return false;
        vector<bool> sub(s.length()+1);
        sub[0] = true;
        for (int i=0; i<s.length(); i++) {
            if (!sub[i]) continue;
            for (string word : wordDict) {
                int end = i+word.length();
                if (end > s.length() || sub[end])
                    continue;
                if (s.substr(i, word.length())==word) {
                    sub[end] = true;
                }
            }
        }
        return sub[s.length()];
    }
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i=1; i<size()+1; i++) {
            int j = i;
            while (j>=0 && dp[i]==0) {
                if (dp[j]==1 && wordDict.find(s.substr(j, i-j))!=wordDict.end()) {
                    dp[i] = 1;
                } else {
                    j--;
                }
            }
        }
        return dp[s.size()] == 1;
    }
};
