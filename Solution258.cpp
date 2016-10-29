
//题目258，Add Digits 加数字

class Solution {
public:
    int addDigits(int num) {
        int res = addNext(num);
        while (res >= 10) {
            res = addNext(res);
        }
        return res;
    }
    int addNext(int num) {
        int ret = 0;
        while (num) {
            ret += num%10;
            num /= 10;
        }
        return ret;
    }
};

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            num = (num/10) + num%10;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9 + 1;
    }
};
