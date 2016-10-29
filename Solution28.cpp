
//题目28，Implement strStr() 实现strStr()函数

//strStr()函数功能，用于判断字符串needle是否是haystack的子串。如果是，则该函数返回needle在haystack中首次出现的地址；否则，返回-1。

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; ; i++) {
            for (int j=0; ; j++) {
                if (j == needle.size()) return i;
                if (i+j == haystack.size()) return -1;
                if (needle[j] != haystack[i+j]) break;
            }
        }
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i=0; i<=m-n; ++i) {
            int j = 0;
            for (j = 0; j<n; ++j)
                if (haystack[i+j]!=needle[j]) break;
            if (j == n) return i;
        }
        return -1;
    }
};
