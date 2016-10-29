
//题目20，Valid Parentheses，验证括号是否合法

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for (auto c : s) {
            if (left.find(c) != string::npos) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top()!=left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c=='(' || c=='[' || c=='{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (c==')' && st.top()!='(') return false;
                if (c==']' && st.top()!=']') return false;
                if (c=='}' && st.top()!='}') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
