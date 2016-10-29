
//题目159，Longest Substring with At Most Two Distinct Characters 最多有两个不同字符的最长子串
//反正去掉重复个数最少的，保留相同元素最多的

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i=0; i<s.size(); ++i) {
            ++m[s[i]];
            while (m.size()>2) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            res = max(res, i-left+1);
        }
    }
};

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i=0; i<s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > 2) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};

//这种解法仅适用于于不同字符数为2个的情况，如果为k个的话，还是需要用上面两种解法。
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = -1, res = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i]==s[i-1]) ++i;
            if (right>=0 && s[right]!=s[i]) {
                res = max(res, i-left);
                left = right+1;
            }
            right = i-1;
        }
        return max(s.size()-left, res);
    }
};
