
//题目263，Ugly Number 丑陋数
//题目264，Ugly Number II

//丑数具有如下特征：1是丑数，丑数可以表示为有限个2、3、5的乘积。
//我们把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。习惯上我们把1当做是第一个丑数。

class Solution {
public:
    bool isUgly(int num) {
        while (num >= 2) {
            if (num%2 == 0) num /= 2;
            else if (num%3 == 0) num /= 3;
            else if (num%5 == 0) num /= 5;
            else return false;
        }
        return num == 1;
    }
};

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num%2 == 0) num /= 2;
        while (num%3 == 0) num /= 3;
        while (num%5 == 0) num /= 5;
        return num == 1;
    }
};

class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++) {
            while (num % i == 0)
                num /= i;
        }
        return num == 1;
    }
};
