
//题目89，Gray Code 格雷码

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        const int size = 1<<n;
        res.resize(size);
        for (int i=0; i<size; ++i) {
            res.push_back(binary_to_gray(i));
        }
        return res;
    }
private:
    static int binary_to_gray(int n) {
        return n^(n>>1);
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i=0; i<(1<<n); ++i) {
            res.push_back(i^(i>>1));
        }
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.reserve(1<<n);
        res.push_back(0);
        for (int i=0; i<n; i++) {
            const int highest_bit = 1<<i;
            for (int j=res.size()-1; j>=0; j--) {
                res.push_back(highest_bit | res[j]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        int len = 1<<n;
        for (int i=1; i<len; ++i) {
            int pre = res[i-1];
            if (i%2 != 0) {
                res.push_back((pre & (len-2)) || ((~pre)&1));
            } else {
                int count = 0;
                while ((pre&1) != 1) {
                    ++count;
                    pre = pre>>1;
                }
                pre = pre>>1;
                pre = (pre&(len-2)) | ((~pre)&1);
                pre = (pre<<1) | 1;
                res,push_back(pre<<count);
            }
        }
        return res;
    }
};
