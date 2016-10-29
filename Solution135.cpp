
//题目135，Candy 分糖果问题

class Solution {
public:
    int candy(vector<int> &ratings) {
        int res = 0;
        vector<int> num(ratings.size(), 1); //初始化每人一颗糖果
        for (int i=0; i<(int)ratings.size()-1; ++i) {
            //从左到右，如果右边小朋友高，则相对于该同学多加一颗糖
            if (ratings[i+1] > ratings[i]) num[i+1] = num[i] + 1;
        }
        for (int i=(int)ratings.size()-1; i>0; --i) {
            //从右向左，同上
            if (ratings[i-1] > ratings[i]) num[i-1] = max(num[i]+1, num[i-1]);
        }
        for (int i=0; i<num.size(); ++i) {
            res += num[i];
        }
        return res;
    }
};

class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        vector<int> increment(n);
        for (int i=1, inc=1; i<n; i++) {
            if (ratings[i] > ratings[i-1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        for (int i=n-2, inc=1; i>=0; i--) {
            if (ratings[i] > ratings[i+1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        return accumulate(&increment[0], &increment[0]+n, n);
    }
};

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> f(ratings.size());
        int sum = 0;
        for (int i=0; i<ratings.size(); ++i)
            sum += solve(ratings, f, i);
        return sum;
    }
    int solve(const vector<int> &ratings, vector<int> &f, int i) {
        if (f[i] == 0) {
            f[i] = 1;
            if (i>0 && ratings[i] > ratings[i-1])
                f[i] = max(f[i], solve(ratings, f, i-1) + 1);
            if (i<ratings.size()-1 && ratings[i]>ratings[i+1])
                f[i] = max(f[i], solve(ratings, f, i+1) + 1);
        }
        return f[i];
    }
};
