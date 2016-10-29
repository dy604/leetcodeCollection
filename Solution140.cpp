
//题目140，Word Break II 拆分词句之二

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string out;
        vector<bool> possible(s.size()+1, true);
        wordBreakDFS(s, wordDict, 0, possible, out, res);
        return res;
    }
    void wordBreakDFS(string &s, unordered_set<string> &wordDict, int start, vector<bool> &possible, string &out, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(out.substr(0, out.size()-1));
            return;
        }
        for (int i=start; i<s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            if (wordDict.find(word)!=wordDict.end() && possible[i+1]) {
                out.append(word).append(" ");
                int oldSize = res.size();
                wordBreakDFS(s, wordDict, i+1, possible, out, res);
                if (res.size()==oldSize) possible[i+1] = false;
                out.resize(out.size()-word.size()-1);
            }
        }
    }
};

class Solution {
public: //动态规划解
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        //长度为n的字符串有n+1个隔板
        vector<bool> f(s.length()+1, false); //动态规划存储数组，f(i)表示s[0,i]是否可以分词
        //prev[i][j]为true，表示s[j,i)区间是一个合法单词，可以从j处切开
        //第一行未用
        vector<vector<bool>> prev(s.length()+1, vector<bool>(s.length()));
        f[0] = true;
        for (int i=1; i<=s.length(); ++i) {
            for (int j=i-1; j>=0; --j) {
                if (f[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    f[i] = true;
                    prev[i][j] = true;
                }
            }
        }
        vector<string> res;
        vector<string> path;
        genPath(s, prev, s.length(), path, res);
        return res;
    }
private:
    //DFS遍历树，生成路径
    void genPath(const string &s, const vector<vector<bool>> &prev, int cur, vector<string> &path, vector<string> &res) {
        if (cur == 0) {
            string tmp;
            for (auto iter=path.crbegin(); iter!=path.crend(); ++iter)
                tmp += *iter + " ";
            tmp.erase(tmp.end()-1);
            res.push_back(tmp);
        }
        for (int i=0; i<s.size(); ++i) {
            if (prev[cur][i]) {
                path.push_back(s.substr(i, cur-i));
                genPath(s, prev, i, path, res);
                path.pop_back();
            }
        }
    }
};
