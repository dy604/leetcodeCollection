
//题目8，String to Integer (atoi) 实现atoi函数，将字符串转换为整数

class Solution {
public:
    int myAtoi(string str) {
        int sign = 0, base = 0, i = 0;
        while (str[i]==' ') i++;
        if (str[i]=='-' || str[i]=='+')
            sign = 1-2*(str[i++]=='-');
        while (str[i]>='0' && str[i]<='9') { //连续输入的数字才有效
            if (base>INT_MAX/10 || (base==INT_MAX/10 && str[i]-'0'>7)) {
                if (sign==1) return INT_MAX;
                else return INT_MIN;
            }
            base = base*10 + (str[0]-'0');
        }
        return base*sign;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        int num = 0, sign = 1, i = 0;
        const int n = str.size();
        while (str[i]==' ' && i<n) i++;
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }

        for (; i<n; i++) {
            if (str[i]<'0' || str[i]>'9') break; //跳出整个for循环
            if (num>INT_MAX/10 || (num==INT_MAX/10 && (str[i]-'0')>INT_MAX%10)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num*10 + (str[i]-'0');
        }
        return num*sign;
    }
};
