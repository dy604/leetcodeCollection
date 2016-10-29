
//题目266，Palindrome Permutation 回文全排列
//题目267，Palindrome Permutation II

//检查给定字符串的全排列中是否有回文串
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (auto a : s) ++m[a];
        for (auto it=m.begin(); it!=m.end(); ++it) {
            if (it->second % 2) ++cnt;
        }
        return cnt == 0 || (s.size()%2 == 1 && cnt == 1);
    }
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> t;
        for (auto a : s) {
            if (t.find(a) == t.end()) t.insert(a);
            else t.erase(a);
        }
        return t.empty() || t.size() == 1;
    }
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (auto a : s) {
            b.flip(a); //将b中的位，0变1,1变0；
        }
        return b.count() < 2;
    }
};
