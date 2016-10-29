
//题目291，Word Pattern II 词语模式之二
//题目290，Word Pattern 词语模式

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        return helper(pattern, 0, str, 0, m);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i=r; i<str.size(); ++i) {
            string t = str.substr(r, i-r+1);
            if (m.count(c) && m[c]==t) {
                if (hekper(pattern, p+1, str, i+1, m)) return true;
            } else if (!m.count(c)) {
                bool b = false;
                for (auto it : m) {
                    if (it.second == t) b = true;
                }
                if (!b) {
                    m[c] = t;
                    if (helper(pattern, p+1, str, i+1, m)) return true;
                    m.erase(c);
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        set<string> s;
        return helper(pattern, 0, str, 0, m, s);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m, set<string> &s) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i=r; i<str.size(); ++i) {
            string t = str.substr(r, i-r+1);
            if (m.count(c) && m[c]==t) {
                if (helper(pattern, p+1, str, i+1, m, s)) return true;
            } else if (!m.count(c)) {
                if (s.count(t)) continue;
                m[c] = t;
                s.insert(t);
                if (helper(pattern, p+1, str, i+1, m, s)) return true;
                m.erase(c);
                s.erase(t);
            }
        }
        return false;
    }
};

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty()) return str.empty();
        if (m.count(pattern[0])) {
            string t = m[pattern[0]];
            if (t.size() > str.size() || str.substr(0, t.size()) != t) return false;
            if (wordPatternMatch(pattern.substr(1), str.substr(t.size()))) return true;
        } else {
            for (int i = 1; i <= str.size(); ++i) {
                if (s.count(str.substr(0, i))) continue;
                m[pattern[0]] = str.substr(0, i);
                s.insert(str.substr(0, i));
                if (wordPatternMatch(pattern.substr(1), str.substr(i))) return true;
                m.erase(pattern[0]);
                s.erase(str.substr(0, i));
            }
        }
        return false;
    }
    unordered_map<char, string> m;
    unordered_set<string> s;
};
