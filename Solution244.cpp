
//题目244，Shortest Word Distance II 最短单词距离之二
//题目243，Shortest Word Distance
//题目245，Shortest Word Distance III

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); ++i)
            m[words[i]].push_back(i);
    }
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int i=0; i<m[word1].size(); ++i) {
            for (int j=0; j<m[word2].size(); ++j) {
                res = min(res, abs(m[word1][i] - m[word2][j]));
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<int>> m;
};

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); ++i)
            m[words[i]].push_back(i);
    }
    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i<m[word1].size() && j<m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
        }
    }
private:
    unordered_map<string, vector<int>> m;
};
