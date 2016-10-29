
//题目168，Excel Sheet Column Title 求Excel表列名称
//题目171，Excel Sheet Column Number

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n) {
            ret = (char)((n-1)%26 + 'A') + ret;
            n = (n-1)/26;
        }
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(n/26) + (char)(--n%26+'A');
    }
};
