
//题目6，ZigZag Conversion 给定Z字形的字符串，以及行数，将给定字符串逐行读取

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res = "";
        int size = 2*numRows-2;
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<s.size(); j+=size) {
                res += s[j];
                int tmp = j+size-2*i;
                if (i!=0 && i!=numRows-1 && tmp<s.size()) res+=s[tmp];
            }
        }
        return s;
    }
};

public class Solution {
    public String convert(String s, int numRows) {
        char[] c = s.toCharArray();
        int len = c.length;

        StringBuffer[] sb = new StringBuffer[numRows];
        for (int i=0; i<sb.length; i++) {
            sb[i] = new StringBuffer();
        }

        int i=0;
        while (i < len) {
            for (int idx=0; idx<numRows && i<len; idx++) {
                sb[idx].append(c[i++]);
            }
            for (int idx=numRows-2; idx>=1 && i<len; idx++) {
                sb[idx].append(c[i++]);
            }
        }
        for (int idx=1; idx<numRows; idx++)
            sb[0].append(sb[idx]);
        return sb[0].toString();
    }
}
