
//题目7，Reverse Integer 翻转整数，将原整数的高位变低位，低位变高位

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        for ( ; x; x/=10) {
            res = res*10 + x%10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX/10) return 0;
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
};

class Solution {
public:
    int reverse(int x) {
        int flag = x>0 ? 1 : -1;
        int res = 0;
        x = x>0 ? x : -x;
        while (x>0) {
            if ((2147483647.0-x%10)/10 < res) return 0;
            res = res*10 + x%10;
            x = x/10;
        }
        return res*flag;
    }
};
