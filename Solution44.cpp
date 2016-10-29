
//题目44，Wildcard Matching 通配符匹配

//迭代实现
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, match = 0, starIdx = -1;
        while (si < s.size()) {
            if (pi<p.size() && (p[pi]=='?' || p[pi]==s[si])) {
                si++;
                pi++;
            } else if (pi<p.size() && p[pi]=='*') {
                starIdx = pi;
                match = si;
                pi++;
            } else if (starIdx != -1) {
                pi = starIdx + 1;
                match++;
                si = match;
            } else return false;
        }
        while (pi<p.size() && p[pi]=='*')
            pi++;
        return pi==p.size();
    }
};

//动态规划实现
public class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        int count = 0;
        for (int i=0; i<n; i++) {
            if (p.charAt(i)=='*') count++;
        }
        if (count==0 && m!=n) return false;
        else if (n-count>m) return false;

        boolean[] match = new boolean[m+1];
        match[0] = true;
        for (int i=0; i<m; i++) {
            match[i+1] = false;
        }
        for (int i=0; i<n; i++) {
            if (p.charAt(i)=='*') {
                for (int j=0; j<m; j++) {
                    match[j+1] = match[j] || match[j+1];
                }
            } else {
                for (int j=m-1; j>=0; j--) {
                    match[j+1] = (p.charAt(i)=='?' || p.charAt(i)==s.charAt(j)) && match[j];
                }
                match[0] = false;
            }
        }
        return match[m];
    }
}

//递归实现
class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0) > 1;
    }
    int dfs(string &s, string &p, int si, int pi) {
        if (si==s.size() and pi==p.size()) return 2;
        if (si==s.size() and p[pi]!='*') return 0;
        if (pi==p.size()) return 1;
        if (p[pi]=='*') {
            if (pi+1<p.size() and p[pi+1]=='*')
                return dfs(s, p, si, pi+1);
            for (int i=0; i<=s.size()-si; ++i) {
                int ret = dfs(s, p, si+i, pi+1);
                if (ret==0 or ret==2) return ret;
            }
        }
        if (p[pi]=='?' or s[si]==p[pi])
            return dfs(s, p, si+1, pi+1);
        return 1;
    }
};
