
//题目9，Palindrome Number 验证一个整数是否是回文数

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x!=0 && x%10==0)) return false;
        int ret = 0;
        while (x > ret) {
            ret = ret*10 + x%10;
            x /= 10;
        }
        return (x==ret) || (x==ret/10);
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x/div >= 10) div *= 10;
        while (x > 0) {
            int left = x/div;
            int right = x%10;
            if (left != right) return false;
            x = (x%div)/10;
            div /= 100;
        }
        return true;
    }
};
