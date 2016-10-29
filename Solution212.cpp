
//题目212，Word Search II 词语搜索之二
//题目79，Word Search

class Solution {
public://基于字典树求解
    struct TrieNode { //字典树节点
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {//字典树
        TrieNode *root;
        Trie() : root(new TrieNode()) {};
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a); //根据给定的单词列表构造字典树
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char>> &board, TrieNode *p, int i, int j, vector<vector<int>> &visit, vector<string> &res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};

public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<>();
        TrieNode root = buildTrie(words); //根据给定的单词列表构造字典树
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

    public void dfs(char[][] board, int i, int j, TrieNode p, List<String> res) {
        char c = board[i][j];
        if (c=='#' || p.next[c-'a']==null) return ;
        p = p.next[c-'a'];
        if (p.word != null) {  //找到一个
            res.add(p.word);
            p.word = null; //删除重复的
        }

        board[i][j] = '#';
        if (i>0) dfs(board, i-1, j, p, res);
        if (j>0) dfs(board, i, j-1, p, res);
        if (i<board.length-1) dfs(board, i+1, j, p, res);
        if (j<board[0].length-1) dfs(board, i, j+1, p, res);
        board[i][j] = c; //恢复原来的字符，下一次递归使用
    }

    public TrieNode buildTrie(String[] words) { //由单词数组生成字典树
        TrieNode root = new TrieNode();
        for (String w : words) {
            TrieNode p = root;
            for (char c : w.toCharArray()) { //将每个单词转换为字符数组
                int i = c - 'a'; //字符转换为数字
                if (p.next[i] == null) p.next[i] = new TrieNode();
                p = p.next[i];
            }
            p.word = w;
        }
        return root;
    }

    class TrieNode { //内部类，构造字典树节点
        TrieNode[] next = new TrieNode[26];
        String word;
    }
}
