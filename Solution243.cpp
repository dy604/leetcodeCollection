
//题目243，Shortest Word Distance 最短单词距离
//题目244，Shortest Word Distance II
//题目245，Shortest Word Distance III

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> idx1, idx2;
        int res = INT_MAX;
        for (int i=0; i<words.size(); ++i) {
            if (words[i] == word1) idx1.push_back(i);
            else if (words[i] == word2) idx2.push_back(i);
        }
        for (int i=0; i<idx1.size(); ++i) {
            for (int j=0; j<idx2.size(); ++j) {
                res = min(res, abs(idx1[i] - idx2[j]));
            }
        }
        return res;
    }
};

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i=0; i<words.size(); ++i) {
            if (words[i] == word1) p1 = i;
            if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
        }
        return res;
    }
};

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i=0; i<words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && words[idx] != words[i]) {
                    res = min(res, abs(idx - i));
                }
                idx = i;
            }
        }
        return res;
    }
};
