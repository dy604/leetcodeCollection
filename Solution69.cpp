
//题目69，Sqrt(x) 求平方根

//利用二分搜索
class Solution {
public:
    int mySqrt(int x) {
        if (x<=1) return x;
        int left = 1, right = x;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (mid <= x/mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left-1;
    }
};

//利用位操作
public class Solution {
    public int mySqrt(int x) {
        long ans = 0;
        long bit = 1l << 16;
        while (bit > 0) {
            ans |= bit;
            if (ans*ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }
        return (int)ans;
    }
}

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double res = 1, pre = 0;
        while (res != pre) {
            pre = res;
            res = (res+x/res)/2;
        }
        return int(res);
    }
};
