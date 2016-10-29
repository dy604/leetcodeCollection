
//题目17，Letter Combinations of a Phone Number，电话号码的字母组合

class Solution {
public:
    const vector<string> keyboard = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size()==0)
            return res;
        dfs(digits, 0, "", res);
        return res;
    }
    void dfs(const string digits, int cur, string path, vector<string> &res) {
        if (cur == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto c : keyboard[digits[cur] - '0') {
            dfs(digits, cur+1, path+c, res);
        }
    }
};

public class Solution {
    public List<String> letterCombination(String digits) {
        LinkedList<String> ans = new LinkedList<String>();
        if (digits.length() == 0)
            return ans;
        String[] mapping = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.add("");
        for (int i=0; i<digits.length(); i++) {
            int x = Character.getNumericValue(digits.charAt(i));
            while (ans.peek().length() == i) {
                String t = ans.remove();
                for (char s : mapping[x].toCharArray())
                    ans.add(t+s);
            }
        }
        return ans;
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return vector<string>();
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i=0; i<digits.size(); ++i) {
            int num = digits[i]-'0';
            if (num < 0 || num>9) break;
            const string &candidate = v[num];
            if (candidate.empty()) continue;
            vector<string> tmp;
            for (int j=0; j<candidate.size(); ++j) {
                for (int k=0; k<res.size(); ++k) {
                    tmp.push_back(res[k]+candidate[j]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> letterCombination(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i=0; i<digits.size(); ++i) {
            int n = res.size();
            string str = dict[digits[i]-'2'];
            for (int j=0; j<n; ++j) {
                string tmp = res.front();
                res.erase(res.begin());
                for (int k=0; k<str.size(); ++k) {
                    res.push_back(tmp+str[k]);
                }
            }
        }
        return res;
    }
};
