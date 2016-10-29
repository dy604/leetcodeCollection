
//��Ŀ8��String to Integer (atoi) ʵ��atoi���������ַ���ת��Ϊ����

class Solution {
public:
    int myAtoi(string str) {
        int sign = 0, base = 0, i = 0;
        while (str[i]==' ') i++;
        if (str[i]=='-' || str[i]=='+')
            sign = 1-2*(str[i++]=='-');
        while (str[i]>='0' && str[i]<='9') { //������������ֲ���Ч
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
            if (str[i]<'0' || str[i]>'9') break; //��������forѭ��
            if (num>INT_MAX/10 || (num==INT_MAX/10 && (str[i]-'0')>INT_MAX%10)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num*10 + (str[i]-'0');
        }
        return num*sign;
    }
};
