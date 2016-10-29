
//题目231，Power of Two 判断2的次方数

//不断的除以2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n==1 || (n%2==0 && isPowerOfTwo(n/2)));
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n && n%2==0) {
            n /= 2;
        }
        return n==1;
    }
};

//直接对整数的二进制表示中1的个数计数，是二的次方数的话，只有一个1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        while (n > 0) {
            count += (n&1);
            n >>= 1;
        }
        return count==1;
    }
};

//直接利用n&&n-1结果应该为0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && (!(n&(n-1)));
    }
};
