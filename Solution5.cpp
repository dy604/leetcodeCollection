
//题目5，Longest Palindromic Substring 找到给定字符串中最长回文子串

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (s <= 1) return s;

        int longestBegin = 0;
        int maxLen = 0;
        bool table[1000][1000] = {false};

        for (int i=0; i<n; i++) {
            table[i][i] = true;
        }

        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                longestBegin = i;
                maxLen = 2;
            }
        }

        for (int len=3; len<=n; len++) {
            for (int i=0; i<n-len+1; i++) {
                int j = i+len-1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(longestBegin, maxLen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<i; j++) {
                dp[j][i] = (s[i] == s[j] && (i-j<2 || dp[j+1][i-1]));
                if (dp[j][i] && len<i-j+1) {
                    len = i-j+1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right-left+1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        string longest = s.substr(0, 1);

        for (int i=0; i<n-1; i++) {
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;
            string p2 = expandAroundCenter(s, i, i+1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
    string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = s.size();

        while (l>=0 && r<=n-1 && s[l]==s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;

        int min_start = 0, max_len = 1;
        for (int i=0; i<s.size(); ) {
            if (s.size()-i < max_len/2)
                break;
            int j=i, k=i;
            while (k<s.size()-1 && s[k+1]==s[k])
                k++;
            i = k+1;
            while (k<s.size()-1 && s[k+1]==s[j-1]){
                ++k;
                --j;
            }
            int new_len = k-j+1;
            if (new_len > max_len) {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};

//马拉车算法Manacher's Algorithm

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for (int i=0; i<s.size(); i++) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i=0; i<t.size(); i++) {
            p[i] = mx>i ? min(p[2*id-i], mx-i) : 1;
            while (t[i+p[i]] == t[i-p[i]]) ++p[i];
            if (mx < i+p[i]) {
                mx = i+p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId-resMx)/2, resMx-1);
    }
};
