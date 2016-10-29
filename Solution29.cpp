
//题目29，Divide Two Integers
//不使用乘除法和取模运算来完成两个整数相除，如果溢出，则返回MAX_INT。

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = ((dividend<0)^(divisor<0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp<<1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;
        long long m = abs((long long)dividend), n = abs((long long)divisor);
        if (m < n) return 0;
        long long t = n, p = 1;
        while (m > (t<<1)) {
            t <<=1 ;
            p <<= 1;
        }
        res += p + divide(m-t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};
