
//题目52，N-Queens II N皇后问题之二

class solution {
public:
    int totalNQueens(int n) {
        int res;
        vector<int> pos(n, -1);
        totalNQueensDFS(pos, 0, res);
        return res;
    }
    void totalNQueensDFS(vector<int> &pos, int row, int res) {
        int n = pos.size();
        if (row == n) res++;
        else {
            for (int col=0; col<n; ++col) {
                if (isValid(pos, row, col)) {
                    pos[row] = col;
                    totalNQueensDFS(pos, row+1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i=0; i<row; ++i) {
            if (col==pos[i] || abs(row-i)==abs(col-pos[i]))
                return false;
        }
        return true;
    }
};

class Solution {
private:
    int res;
public:
    int totalNQueens(int n) {
        vector<int> state(n, -1);
        for (int row=0, col; ; ) {
            for (col=state[row]+1; col<n; ++col) {
                if (isValid(state, row, col)) {
                    state[row] = col;
                    if (row == n-1) res++;
                    else {
                        row++;
                        break;
                    }
                }
            }
            if (col == n) {
                if (row == 0) break;
                state[row] = -1;
                row--;
            }
        }
        return res;
    }
    bool isValid(vector<int> &state, int row, int col) {
        for (int i=0; i<row; ++i) {
            if (col==state[i] || abs(row-i)==abs(col-state[i]))
                return false;
        }
        return true;
    }
};
