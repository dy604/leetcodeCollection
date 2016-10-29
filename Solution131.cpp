
//题目131，Palindrome Partitioning 拆分回文串
//题目132，Palindrome Partitioning II

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, path, res, 0);
        return res;
    }
    void dfs(string &s, vector<string> &path, vector<vector<string>> &res, int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i=start; i<s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                dfs(s, path, res, i+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start<end && s[start]==s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, path, res, 0, 1);
        return res;
    }
    void dfs(string &s, vector<string> &path, vector<vector<string>> &res, int prev, int start) {
        if (start == s.size()) {
            if (isPalindrome(s, prev, start-1)) {
                path.push_back(s.substr(prev, start-prev));
                res.push_back(path);
                path.pop_back();
            }
            return ;
        }
        dfs(s, path, res, prev, start+1);
        if (isPalindrome(s, prev, start-1)) {
            path.push_back(s.substr(prev, start-prev));
            dfs(s, path, res, start, start+1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start<end && s[start]==s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};

//动态规划
class Solution {
public:
    vector<vector<int>> partition(string s) {
        const int n = s.size();
        bool p[n][n];
        fill_n(&p[0][0], n*n, false);
        for (int i=n-1; i>=0; --i) {
            for (int j=i; j<n; ++j) {
                p[i][j] = s[i]==s[j] && ((j-i<2) || p[i+1][j-1]);
            }
        }
        vector<vector<string>> sub_palins[n];
        for (int i=n-1; i>=0; --i) {
            for (int j=i; j<n; ++j) {
                if (p[i][j]) {
                    const string palindrome = s.substr(i, j-i+1);
                    if (j + 1 < n) {
                        for (auto v : sub_palins[j + 1]) {
                            v.insert(v.begin(), palindrome);
                            sub_palins[i].push_back(v);
                        }
                    } else {
                        sub_palins[i].push_back(vector<string> { palindrome });
                    }
                }
            }
        }
        return sub_palins[0];
    }
};
