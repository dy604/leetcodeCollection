
//题目13，Roman to Integer 罗马数字转换为整数

class Solution {
public:
    int romanToInt(string n) {
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            if (i>0 && map(s[i])>map(s[i-1])) {
                res += (map(s[i]) - 2*map(s[i-1]));
            } else {
                res += map(s[i]);
            }
        }
        return res;
    }
    inline int map(const char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i=0; i<s.size(); ++i) {
            int val = m[s[i]];
            if (i==s.size()-1 || m[s[i+1]]<=m[s[i]]) res += val;
            else res -= val;
        }
        return res;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i=0; i<s.size(); ++i) {
            if (i==0 || m[s[i]]<=m[s[i-1]]) res += m[s[i]];
            else res += m[s[i]]-2*m[s[i-1]];
        }
        return res;
    }
};
