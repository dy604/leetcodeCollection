
//题目201，Bitwise AND of Numbers Range 数字范围位相与

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while ((m&d) != (n&d)) {
            d <<= 1;
        }
        return m&d;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m<<i);
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n>m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};
