
//题目172，Factorial Trailing Zeroes 求阶乘末尾零的个数

class Solution {
public:
    int trailingZeroes(int n) {
        return n==0 ? 0 : n/5+trailingZeroes(n/5);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        long long x = 5;
        int ans = 0;
        while (n >= x) {
            ans += n/x;
            x *= 5;
        }
        return ans;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (long long i=5; n/i>0; i*=5) {
            res += (n/i);
        }
        return res;
    }
};
