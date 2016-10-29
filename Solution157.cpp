
//题目157，Read N Characters Given Read4 用Read4来读取N个字符
//题目158，Read N Characters Given Read4 II - Call multiple times

int read4(char *buf);

//迭代
class solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i=0; i<=n/4; ++i) {
            int cur = read4(buf + res);
            if (cur == 0) break;
            res += cur;
        }
        return min(res, n);
    }
};

//递归
class Solution {
public:
    int read(char *buf, int n) {
        int t = read4(buf);
        if (t >= n) return n;
        if (t < 4) return t;
        return 4+read(&buf[4], n-4);
    }
};
