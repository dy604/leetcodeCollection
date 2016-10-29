
//题目58，Length of Last Word 最后一个单词长度

//从前往后
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, i = 0;
        while (s[i]) {
            if (s[i++] != ' ')
                count++;
            else if (s[i] && s[i]!=' ') {
                count = 0;
            }
        }
        return count;
    }
};

class Solution {
public:
    int LengthOfLastWord(string s) {
        int res = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] != ' ') {
                if (i!=0 && s[i-1]==' ') res = 1;
                else ++res;
            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, i = s.size()-1;
        while (i>=0 && s[i]==' ')
            i--;
        while (i>=0 && s[i]!=' ') {
            count++;
            i--;
        }
        return count;
    }
};
