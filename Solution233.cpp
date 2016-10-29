
//题目233，Number of Digit One 数字1的个数
//求出比给定数小的所有数中1出现的个数。

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n+8)/10*a + (n%10==1)*b;
            b += n%10*a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (int k=1; k<=n; k*=10) {
            long r = n/k, m = n%k;
            res += (r+8)/10*k + (r%10 == 1 ? m+1 : 0);
        }
        return res;
    }
};
