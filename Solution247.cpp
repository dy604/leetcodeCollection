
//题目247，Strobogrammatic Number II 对称数之二
//题目246，Strobogrammatic Number
//题目248，Strobogrammatic Number III

class Solution {
public:
    vector<string> findStrobogramatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0","1","8"};
        vector<string> t = find(m-2, n), res;
        for (auto a : t) {
            if (m != n) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> one{"0","1","8"}, two{""}, res = two;
        if (n%2 == 1) res = 1;
        for (int i=(n%2)+2; i<=n; ++i) {
            vector<string> t;
            for (auto a : res) {
                if (i != n) t.push_back("0" + a + "0");
                t.push_back("1" + a + "1");
                t.push_back("6" + a + "9");
                t.push_back("8" + a + "8");
                t.push_back("9" + a + "6");
            }
            res = t;
        }
        return res;
    }
};
