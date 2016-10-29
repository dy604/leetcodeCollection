
//题目294，Flip Game II 翻转游戏之二
//题目293，Flip Game

class Solution {
public:
    bool canWin(string s) {
        for (int i=1; i<s.size(); ++i) {
            if (s[i]=='+' && s[i-1]=='+' && !canWin(s.substr(0, i-1) + "--" + s.substr(i+1))) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canWin(string s) {
        for (int i=-1; (i=s.find("++", i+1))>=0; ) {
            if (!canWin(s.substr(0,i) + "--" + s.substr(i+2))) {
                return true;
            }
        }
        return false;
    }
};
