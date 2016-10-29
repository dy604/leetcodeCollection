
//题目293，Flip Game 翻转游戏
//题目294，Flip Game II

class Solution {
public:
    vector<string> generatePossibleNextMove(string s) {
        vector<string> res;
        for (int i=1; i<s.size(); ++i) {
            if (s[i] == '+' && s[i-1] == '+') {
                res.push_back(s.substr(0, i-1) + "--" + s.substr(i+1));
            }
        }
        return res;
    }
};
