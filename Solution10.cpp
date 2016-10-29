
//题目10，Container With Most Water 正则表达式匹配

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1)
            return (s.size()==1 && (s[0]==p[0] || p[0]=='.'));
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0]==p[0] || p[0]=='.')) {
            if (isMatch(s, p.substr(2)) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[1] != '*') {
            if (s[0]==p[0] || (!s.empty() && p[0]=='.')) {
                return isMatch(s.substr(1), p.substr(1));
            } else {
                return false;
            }
        } else {
            while (p[0]==s[0] || (p[0]=='.' && !s.empty())) {
                if (isMatch(s, p.substr(2)))
                    return true;
                s = substr(1);
            }
            return isMatch(s, p.substr(2));
        }
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //f[i][j]代表s的前i段与p的前j是否匹配
        vector<vector<bool>> f(m+1, vector<bool>(n+1, false));

        f[0][0] = true;
        for (int i=1; i<=m; i++)
            f[i][0] = false;

        for (int j=1; j<=n; j++)
            f[0][j] = j>1 && '*'==p[j-1] && f[0][j-2];

        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                if (p[j-1] != '*')
                    f[i][j] = f[i-1][j-1] && (s[i-1]==p[j-1] || '.'==p[j-1]);
                else
                    f[i][j] = f[i][j-2] || (s[i-1]==p[j-2] || '.'==p[j-2]) && f[i-1][j];

            return f[m][n];
    }
};
