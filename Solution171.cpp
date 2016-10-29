
//题目171，Excel Sheet Column Number 求Excel表列序号
//题目168，Excel Sheet Column Title

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        if (s.size()==0) return res;
        for (int i=0; i<s.size(); i++) {
            res = res*26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};
