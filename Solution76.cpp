
//题目76，Minimum Window Substring 最小窗口子串

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()>s.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = s.size()+1;
        unordered_map<char, int> m;
        for (int i=0; i<t.size(); ++i) {
            if (m.find(t[i])!=m.end()) ++m[t[i]];
            else m[t[i]] = 1;
        }
        for (int right=0; right<s.size(); ++right) {
            if (m.find(s[right]]) != m.end()) {
                --m[s[right]];
                if (m[s[right]]>=0) ++count;
                while (count == t.size()) {
                    if (right-left+1<minLen) {
                        minLen = right-left+1;
                        res = s.substr(left, minLen);
                    }
                    if (m.find(s[left])!=m.end()) {
                        ++m[s[left]];
                        if (m[s[left]]>0) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()>s.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = s.size()+1;
        int tm[256] = {0}, sm[256] = {0};
        for (int i=0; i<t.size(); ++i) ++tm[t[i]];
        for (int right=0; right<s.size(); ++right) {
            if (tm[s[right]]!=0) {
                ++sm[s[right]];
                if (sm[s[right]]<=tm[s[right]]) ++count;
                while (count == t.size()) {
                    if (right-left+1<minlen) {
                        minLen = right-left+1;
                        res = s.substr(left, minLen);
                    }
                    if (tm[s[left]]!=0) {
                        --sm[s[left]];
                        if (sm[s[left]]<tm[s[left]]) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};
