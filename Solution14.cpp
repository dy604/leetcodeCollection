
//��Ŀ14��Longest Common Prefix �ҵ������ַ��������У������ַ����������ǰ׺

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        for (int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++) {
            for (int i=0; i<strs.size(); i++)
                if (idx>=strs[i].size() || (i>0 && strs[i][idx]!=strs[i-1][idx]))
                    return prefix;
        }
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        if (strs.size() == 0) return prefix;

        for (int k=0; k<strs[0].size(); k++) {
            int i = 1;
            for ( ; i<strs.size(); i++) {
                if (strs[i][k] != strs[0][k])
                    return prefix;
            }
            if (i == strs.size())
                prefix += strs[0][k];
        }
        return prefix;
    }
};
