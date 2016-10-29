
//题目93，Restore IP Addresses 复原IP地址

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
    void dfs(string s, int start, int step, string ip, vector<string> &res) {
        if (start==s.size() && step==4) {
            ip.resize(ip.size()-1);
            res.push_back(ip);
            return ;
        }
        if (s.size()-start>(4-step)*3)
            return ;
        if (s.size()-start<(4-step))
            return ;
        int num = 0;
        for (int i=start; i<start+3; i++) {
            num = num*10 + (s[i]-'0');
            if (num <= 255) {
                ip += s[i];
                dfs(s, i+1, step+1, ip+'.', res);
            }
            if (num == 0)
                break;
        }
    }
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s, 4, "", res);
        return res;
    }
    void restore(string s, int k, string out, vector<string> res) {
        if (k == 0) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int i=1; i<=3; ++i) {
                if (s.size()>=i && isValid(s.substr(0,i))) {
                    if (k == 1) restore(s.substr(i), k-1, out+s.substr(0,i), res);
                    else restore(s.substr(i), k-1, out+s.substr(0,i), res);
                }
            }
        }
    }
    bool isValid(string s) {
        if (s.empty() || s.size()>3 || (s.size()>1 && s[0]=='0')) return false;
        int res = atoi(s.c_str());
        return res <= 256 && res >= 0;
    }
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 0, "", res);
        return res;
    }
    void helper(string s, int n, string out, vector<string> &res) {
        if (n == 4) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int k=1; k<4; ++k) {
                if (s.size() < k) break;
                int val = atoi(s.substr(0,k).c_str());
                if (val>255 || k!=std::to_string(val).size()) continue;
                helper(s.substr(k), n+1, out+s.substr(0,k)+(n==3 ? "" : "."), res);
            }
        }
    }
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a=1; a<4; ++a) {
            for (int b=1; b<4; ++b) {
                for (int c=1; c<4; ++c) {
                    for (int d=1; d<4; ++d) {
                        if (a+b+c+d == s.size()) {
                            int A = stoi(s.substr(0,a));
                            int b = stoi(s.substr(a,b));
                            int C = stoi(s.substr(a+b,c));
                            int D = stoi(s.substr(a+b+c, d));
                            if (A<=255 && B<=255 && C<=255 && D<=255) {
                                string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if (t.size() == s.size()+3) res.push_back(t);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
