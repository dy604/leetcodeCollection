
//题目126，Word Ladder II 词语阶梯之二
//题目126，Word Ladder

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_map<string> &wordList) {
        vector<vector<string>> res;
        wordList.insert(endWord);
        vector<string> p;
        p.push_back(beginWord);
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                for (string w : words) wordList.erase(w);
                words.clear();
                level = path.size();
                if (level > minLevel) break;
            }
            string last = path.back();
            for (int i=0; i<last.size(); ++i) {
                string newLast = last;
                for (char ch='a'; ch<='z'; ++ch) {
                    newLast[i] = ch;
                    if (wordList.find(newLast) != wordList.end()) {
                        words.insert(newLast);
                        vector<string> nextPath = path;
                        nextPath.push_back(newLast);
                        if (newLast == endWord) {
                            res.push_back(nextPath);
                            minLevel = level;
                        } else paths.push(nextPath);
                    }
                }
            }
        }
        return res;
    }
};
