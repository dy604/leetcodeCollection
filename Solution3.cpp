
//题目3，Longest Substring Without Repeating Characters 找到给定字符串中最长不包含相同字符的子串

class Solution {
public:
    int lenthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int res = 0, left = -1;
        for (int i=0; i<s.size(); i++) {
            left = max(left, charIndex[s[i]]);
            charIndex[s[i]] = i;
            res = max(res, i-left);
        }
        return res;
    }
};

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int longest = 0;
        for (int i=0; i<s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                j = Math.max(j, map.get(s.charAt(i))+1);
            }
            map.put(s.charAt(i), i);
            longest = Math.max(longest, i-j+1);
        }
        return longest;
    }
}

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        set<int> t;
        int res = 0, left = 0, right = 0;
        for (int i=0; i<s.size(); i++) {
            if (t.find(s[i] == t.end())) {
                s.insert(s[right++]);
                res = max(res, s.size());
            } else {
                t.erase(s[left]);
            }
        }
        return res;
    }
};
