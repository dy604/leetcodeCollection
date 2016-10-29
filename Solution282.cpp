
//题目282，Expression Add Operators 表达式增加操作符

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperatorsDFS(num, target, 0, 0, "", res);
        return res;
    }
    void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out);
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i); //截取下标0到i之间的子串
            if (cur.size() > 1 && cur[0] == '0') return;  //处理第一个为0，长度大于1的数字，不合法
            string next = num.substr(i);  //截取i到最后的子串
            if (out.size() > 0) {
                addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
};

public class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList<String>();
        if (num==null || num.length()==0) return res;
        helper(res, "", num, target, 0, 0, 0);
        return res;
    }
    public void helper(List<String> res, String path, String num, int target, int pos, long eval, long multed) {
        if (pos == num.length() && target == eval) {
            res.add(path);
            return;
        }
        for (int i=pos; i<num.length(); i++) {
            if (i!=pos && num.charAt(pos)=='0') break;
            long cur = Long.parseLong(num.substring(pos, i+1));
            if (pos == 0) {
                helper(res, path+cur, num, target, i+1, cur, cur);
            } else {
                helper(res, path + "+" + cur, num, target, i + 1, eval + cur , cur);
                helper(res, path + "-" + cur, num, target, i + 1, eval -cur, -cur);
                helper(res, path + "*" + cur, num, target, i + 1, eval - multed + multed * cur, multed * cur );
            }
        }
    }
}
