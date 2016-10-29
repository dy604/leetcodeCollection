
//题目205，Isomorphic Strings 同构字符串

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map1[256] = {0};
        int map2[256] = {0};
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (map1[s[i]] != map2[t[i]]) {
                return false;
            }
            map1[s[i]] = i+1;
            map2[t[i]] = i+1;
        }
        return true;
    }
};
