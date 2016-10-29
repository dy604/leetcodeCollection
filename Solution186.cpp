
//题目186，Reverse Words in a String II 翻转字符串中的单词之二
//题目151，Reverse Words in a String

class Solution {
public:
    void reverseWords(string &s) {
        int left = 0;
        for (int i=0; i<s.size(); ++i) {
            if (i==s.size() || s[i]==' ') {
                reverse(s, left, i-1);
                left = i+1;
            }
        }
        reverse(s, 0, s.size()-1);
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left;
            --right;
        }
    }
};
