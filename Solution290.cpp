
//题目290，Word Pattern 词语模式
//题目291，Word Pattern II

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> pat;
        map<string, int> st;
        int i = 0;
        int n = pattern.size();
        istringstream in(str);

        for (string word; in >> word; ++i) {
            if (i==n || pat[pattern[i]] != st[word]) {
                return false;
            }
            pat[pattern[i]] = st[word] = i+1;
        }
        return i==n;
    }
};

public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length()) {
            return false;
        }
        Map index = new HashMap();
        for (Integer i=0; i<words.length; ++i) {
            if (index.put(pattern.charAt(i), i) != index.put(words[i], i)) {
                return false;
            }
        }
        return true;
    }
}
