
//题目151，Reverse Words in a String 翻转字符串中的单词
//题目186，Reverse Words in a String II

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0)
                    s[storeIndex++] = ' ';
                int j = i;
                while (j<s.size() && s[j]!=' ') {
                    s[storeIndex++] = s[j++];
                }
                reverse(s.begin()+storeIndex-(j-i), s.begin()+storeIndex);
                i = j;
            }
        }
        s.erase(s.begin()+storeIndex, s.end());
    }
};

public class Solution {
    public void reverseWords(String s) {
        String[] parts = s.trim().split("\\s+");
        String res = "";
        for (int i=parts.length-1; i>0; i--) {
            res += parts[i] + " ";
        }
        return res + parts[0];
    }
}

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        int l = 0;
        int len = s.length();
        int wordcount = 0;

        while (true) {
            while (i<len && s[i]==' ') i++;
            if (i == len) break;
            if (wordcount) s[j++] = ' ';
            l = j;
            while(i<len && s[i]!=' ')
                s[j++] = s[i++];
            reverse(s, l, j-1);
            wordcount++;
        }
        s.resize(j);
        reverseword(s, 0, j-1);
    }
    void reverseword(string &s, int i, int j) {
        while (i < j) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int pos = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                if (i > pos)
                    res = s.substr(pos, i-pos) + " " + res;
                pos = i + 1;
            } else if (i == s.size()-1) {
                res = s.substr(pos, s.size()-pos) + " " + res;
            }
        }
        s = res.substr(0, res.size()-1);
    }
};
