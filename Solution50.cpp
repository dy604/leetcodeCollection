
//题目50，Pow(x, n) 实现pow(x, n)函数;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n < 0)
            return 1.0/myPow(x, -n);
        return x*myPow(x, n-1);
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == INT_MIN)
                return 1.0/(pow(x, INT_MAX)*x);
            else
                return 1.0/pow(x, -n);
        }
        if (n == 0)
            return 1.0;
        double ans = 1.0;
        for (; n>0; x*=x, n>>1) {
            if (n&1 > 0)
                ans *= x;
        }
        return ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        bitset<32> bit(abs(n));
        double res = 1.0;
        for (int i=bit.size()-1; i>=0; i--) {
            res *= res;
            if (bit[i] == 1)
                res *= x;
        }
        return (n>=0) ? res : 1/res;
    }
};
