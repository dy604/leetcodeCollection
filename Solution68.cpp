
//题目68，Text Justification 文本左右对齐

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            int j = i, len = 0;
            while (j<words.size() && (len+words[j].size()+j-i)<=maxWidth) {
                len += words[j++].size();
            }
            string out;
            int space = maxWidth - len;
            for (int k=i; k<j; ++k) {
                out += words[k];
                if (space > 0) {
                    int tmp;
                    if (j == words.size()) {
                        if (j-k==1) tmp = space;
                        else tmp = 1;
                    } else {
                        if (j-k-1>0) {
                            if (space % (j-k-1)==0) tmp = space/(j-k-1);
                            else tmp = space/(j-k-1)+1;
                        } else tmp = space;
                    }
                    out.append(tmp, ' ');
                    space -= tmp;
                }
            }
            res.push_back(out);
            i = j;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        const int n = words.size();
        int begin = 0, len = 0; // 当前行的起点，当前长度
        for (int i=0; i<n; ++i) {
            if (len+words[i].size()+(i-begin)>maxWidth) {
                res.push_back(connect(words, begin, i-1, len, maxWidth, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        res.push_back(connect(words, begin, n-1, len, maxWidth, true));
        return res;
    }
    //将words[begin, end]连成一个字符串，len表示words[begin, end]所有单词加起来的长度，maxWidth一行长度，is_last是否是最后一行
    string connect(vector<string> &words, int begin, int end, int len, int maxWidth, bool is_last) {
        string s;
        int n = end-begin+1;
        for (int i=0; i<n; ++i) {
            s += words[begin+i];
            addSpace(s, i, n-1, maxWidth-len, is_last);
        }
        if (s.size()<maxWidth) s.append(maxWidth-s.size(), ' ');
        return s;
    }
    //添加空格, i表示当前空隙序号，n表示空隙总数，maxWidth表示总共需要添加的空格数，is_last是否是最后一行
    void addSpace(string &s, int i, int n, int maxWidth, bool is_last) {
        if (n<1 || i>n-1) return;
        int spaces = is_last ? 1 : (maxWidth/n + (i<(maxWidth%n)? 1 : 0));
        s.append(spaces, ' ');
    }
};
