
//题目79，Word Search 词语搜索
//题目212，Word Search II

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int M,N,i,j, sLen = word.size();
        if ((M=board.size()) && (N=board[0].size()) && sLen) {
            for (i=0; i<M; ++i) {
                for (j=0; j<N; ++j) {
                    if (dfs(board, i, j, word, 0, M, N, sLen))
                        return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, int row, int col, const string &word, int start, int M, int N, int sLen) {
        char curC;
        bool res = false;
        if ((curC=board[row][col])!=word[start])
            return false;
        if (start==sLen-1)
            return true;
        board[row][col] = '*';
        if (row>0)
            res = dfs(board, row-1, col, word, start+1, M, N, sLen);
        if (!res && row<M-1)
            res = dfs(board, row+1, col, word, start+1, M, N, sLen);
        if (!res && col>0)
            res = dfs(board, row, col-1, word, start+1, M, N, sLen);
        if (!res && col<N-1)
            res = dfs(board, row, col+1, word, start+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }
};

public class Solution {
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (exist(board,i,j,words,0)) {
                    return true;
                }
            }
        }
        return false;
    }
    private boolean exist(char[][] board, int i, int j, char[] words, int k) {
        if (k==words.length)
            return true;
        if (i<0 || j<0 || i==board.length || j==board[i].length)
            return false;
        if (board[i][j] != words[k])
            return false;
        board[i][j] ^= 256;
        boolean exist = exist(board, i, j+1, words, k+1)
            || exist(board, i, j-1, words, k+1)
            || exist(board, i+1, j, words, k+1)
            || exist(board, i-1, j, words, k+1);
        board[i][j] ^= 256;
        return exist;
    }
}
