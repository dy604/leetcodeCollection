
//题目214，Shortest Palindrome 最短回文串

//KMP算法实现，p[i]表示从t[i]到开头的子串的相同前缀后缀的个数
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size(), 0);
        for (int i=1; i<t.size(); ++i) {
            int j = p[i-1];
            while (j>0 && t[i]!=t[j]) j = p[j-1];
            p[i] = (j += t[i]==t[j]);
        }
        return r.substr(0, s.size()-p[t.size()-1]) + s;
    }
};

//易懂
public class Solution {
    public String shortestPalindrome(String s) {
        int j = 0;
        for (int i=s.length()-1; i>=0; i--) {//匹配前后相同的长度，即回文长度
            if (s.charAt(i) == s.charAt(j)) {//当i = j = 0时，会执行 j += 1则j=1；
                j += 1;
            }
        }
        if (j == s.length()) {//全都是回文的
            return s;
        }
        String suffix = s.substring(j);//j=1时,s.substring(1) = bcd;
        return new StringBuilder(suffix).reverse().toString() + shortestPalindrome(s.substring(0, j)) + suffix;
    }
}

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size(), l;
        for (l=n; l>=0; l--) {
            if (s.substr(0,l)==s2.substr(n-l))
                break;
        }
        return s2.substr(0, n-l) + s;
    }
};
