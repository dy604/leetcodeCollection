
//题目269，Alien Dictionary 另类字典

//BFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char> > s;
        unordered_set<char> ch;
        vector<int> in(256, 0);
        queue<char> q;
        string res = "";
        for (auto a : words) ch.insert(a.begin(), a.end());
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    s.insert(make_pair(words[i][j], words[i + 1][j]));
                    break;
                }
            }
        }
        for (auto a : s) ++in[a.second];
        for (auto a : ch) {
            if (in[a] == 0) {
                q.push(a);
                res += a;
            }
        }
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : s) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};

//DFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26, false));
        vector<bool> path(26, false);
        string res = "";
        for (string word : words) {
            for (char c : word) {
                g[c - 'a'][c - 'a'] = true;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    g[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (!dfs(g, i, path, res)) return "";
        }
        for (int i = 0; i < 26; ++i) {
            if (g[i][i]) res += (char)(i + 'a');
        }
        return string(res.rbegin(), res.rend());
    }
    bool dfs(vector<vector<bool>> &g, int idx, vector<bool> &path, string &res) {
        if (!g[idx][idx]) return true;
        path[idx] = true;
        for (int i = 0; i < 26; ++i) {
            if (i == idx || !g[idx][i]) continue;
            if (path[i]) return false;
            if (!dfs(g, i, path, res)) return false;
        }
        path[idx] = false;
        g[idx][idx] = false;
        res += (char)(idx + 'a');
        return true;
    }
};
