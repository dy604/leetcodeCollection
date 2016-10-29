
//题目12，Integer to Roman 整数转换为罗马数字,
//罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。

class Solution {
public:
    string intToRoman(int num) {
        vector<string> M{"", "M", "MM", "MMM"};
        vector<string> C{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10]
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string res;
        string symble[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        for (int i=0; num!=0; ++i) {
            while (num >= value[i]) {
                num -= value[i];
                str += symble[i];
            }
        }
        return str;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int value[] = {1000, 500, 100, 50, 10, 5, 1};

        for (int n=0; n<7; n+=2) {
            int x = num/value[n];
            if (x < 4) {
                for (int i=1; i<=x; ++i) res += roman[n];
            } else if (x == 4) {
                res = res + roman[n] + roman[n-1];
            } else if (x > 4 && x < 9) {
                res += roman[n-1];
                for (int i=6; i<=x; ++i) res += roman[n];
            } else if (x == 9) {
                res = res + roman[n] + roman[n-2];
            }
            num %= value[n];
        }
        return res;
    }
};
