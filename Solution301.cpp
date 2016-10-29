
//题目301，Remove Invalid Parentheses 移除非法括号

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int left_removed = 0;
        int right_removed = 0;
        for (auto c ：s) {
            if (c == '(') {
                ++left_removed;
            }
            if (c == ')') {
                if (left_removed != 0) {
                    --left_removed;
                } else {
                    ++right_removed;
                }
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", res);
        return vector<string>(res.begin(), res.end());
    }
private:
    void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()) {
            if(left_removed == 0 && right_removed == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        }
        else {
            if(s[index] == '(') {
                if(left_removed > 0) {
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result);
                }
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result);
            }
            if(s[index] == ')') {
                if(right_removed > 0) {
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result);
                }
            }
        }
    }
};

public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new ArrayList<>();
        remove(s, ans, 0, 0, new char[]{'(', ')'});
        return ans;
    }
    public void remove(String s, List<String> ans, int last_i, int last_j, char[] par) {
        for (int stack=0, i=last_i; i<s.length(); ++i) {
            if (s.charAt(i) == par[0]) stack++;
            if (s.charAt(i) == par[1]) stack--;
            if (stack >= 0) continue;
            for (int j=last_j; j<=i; ++j) {
                if (s.charAt(j)==par[1] && (j==last_j || s.charAt(j-1)!=par[1]))
                    remove(s.substring(0,j) + s.substring(j+1, s.length()), ans, i, j, par);
            }
            return;
        }
        String reversed = new StringBuilder(s).reverse().toString();
        if (par[0] == '(')
            remove(reversed, ans, 0, 0, new char[]{')', '('});
        else
            ans.add(reversed);
    }
}
