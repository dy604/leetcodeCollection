
//题目22，Generate Parentheses，生成括号

class Solution {
public: //递归实现
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n > 0)
            generate(n, "", 0, 0, res);
        return res;
    }
    void generate(int n, string s, int l, int r, vector<string> res) {
        if (l == n) {
            res.push_back(s.append(n-r, ')'));
            return ;
        }
        generate(n, s+'(', l+1, r, res);
        if (l > r)
            generate(n, s+')', l, r+1, res);
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n > 0)
            generate(n, n, "", res);
        return res;
    }
    void generate(int leftnum, int rightnum, string s, vector<string> res) {
        if (leftnum==0 && rightnum==0) {
            res.push_back(s);
        }
        if (leftnum > 0) {
            generate(leftnum-1, rightnum, s+'(', res);
        }
        if (leftnum>0 && leftnum<rightnum) {
            generate(leftnum, rightnum-1, s+')', res);
        }
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return vector<string>(1, "");
        if (n == 1)
            return vector<string>(1, "()");
        vector<string> res;
        for (int i=0; i<n; ++i)
            for (auto inner : generateParenthesis(i))
                for (auto outer : generateParenthesis(n-1-i))
                    res.push_back("(" + inner + ")" + outer);
        return res;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> t;
        if (n == 0) t.insert("");
        else {
            vector<string> pre = generateParenthesis(n-1);
            for (auto a : pre) {
                for (int i=0; i<a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin()+i+1, '(');
                        a.insert(a.begin()+i+2, ')');
                        t.insert(a);
                        a.erase(a.begin()+i+1, a.begin()+i+3);
                    }
                }
                t.insert("()" + a);
            }
        }
        return vector<string>(t.begin(), t.end());
    }
};
