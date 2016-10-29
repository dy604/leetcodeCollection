
//题目70，Climbing Stairs 爬梯子问题

//说明原理，会超时，因为做了很多没有意义的分支计算
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1 || n == 2) return n;
        return climbStairs(n-1)+ climbStairs(n-2);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1);
        res[0] = 1;
        res[1] = 1;
        for (int i=2; i<=n; ++i) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
};
