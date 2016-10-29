
//题目242，Valid Anagram 验证变位词

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s==t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> res(26,0);
        for (int i=0; i<s.size(); i++)
            res[s[i]-'a']++;
        for (int i=0; i<t.size(); i++)
            res[t[i]-'a']--;
        for (int i=0; i<res.size(); i++) {
            if (res[i] != 0)
                return false;
        }
        return true;
    }
};
