
//题目30，Substring with Concatenation of All Words 串联所有单词的子串

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for (string w : words) ++m1[w];
        for (int i=0; i<=(int)s.size()-n*m; ++i) {
            unordered_map<string, int> m2;
            int j = 0;
            for (j=0; j<n; ++j) {
                string t = s.substr(i+j*m, m);
                if (m1.find(t)==m1.end()) break;
                ++m2[t];
                if (m2[t] > m1[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = s.size(), cnt = words.size(), len = words[0].size();
        unordered_map<string, int> m1;
        for (string w : words) ++m1[w];
        for (int i=0; i<len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> m2;
            for (int j=i, j<=n-len; j+=len) {
                string t = s.substr(j, len);
                if (m1.count(t)) {
                    ++m2[t];
                    if (m2[t] <= m1[t]) {
                        ++count;
                    } else {
                        while (m2[t] > m1[t]) {
                            string t1 = s.substr(left, len);
                            --m2[t1];
                            if (m2[t1] < m1[t1]) --count;
                            left += len;
                        }
                    }
                    if (count == cnt) {
                        res.push_back(left);
                        --m2[s.substr(left, len)];
                        --count;
                        left += len;
                    }
                } else {
                    m2.clear();
                    count = 0;
                    left = j+len;
                }
            }
        }
        return res;
    }
};
