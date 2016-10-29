
//题目38，Count and Say 计数和读法

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i=0; i<res.size(); i++) {
                int count = 0;
                while ((i+1<res.size()) && (res[i]==res[i+1])) {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i=1; i<n; i++) {
            res = helper(res);
        }
        return res;
    }
    string helper(string s) {
        char c = s[0];
        int count = 1;
        stringstream ss;
        for (int i=1; i<s.size(); i++) {
            if (s[i] != c) {
                ss << count << c;
                c = s[i];
                count = 1;
            } else {
                count++;
            }
        }
        ss << count << c;
        return ss.str();
    }
};
