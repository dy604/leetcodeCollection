
//题目51，N-Queens N皇后问题

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        solveNQueensDFS(pos, 0, res);
        return res;
    }
    void solveNQueensDFS(vector<int> &pos, int row, vector<vector<string>> &res) {
        int n = pos.size();
        if (row == n) {
            vector<string> out(n, string(n, '.'));
            for (int i=0; i<n; ++i) {
                out[i][pos[i]] = 'Q';
            }
            res.push_back(out);
        } else {
            for (int col=0; col<n; ++col) {
                if (isValid(pos, row, col)) {
                    pos[row] = col;
                    solveNQueensDFS(pos, row+1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i=0; i<row; ++i)
            if (col==pos[i] || abs(row-i)==abs(col-pos[i]))
                return false;
        return true;
    }
};

class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueen(int n) {
        vector<int> state(n, -1);
        for (int row=0, col; ; ) {
            for (col=state[row]+1; col<n; col++) {
                if (isValid(state, row, col)) {
                    state[row] = col;
                    if (row == n-1) {
                        vector<string> tmpres(n, string(n, '.'));
                        for (int i=0; i<n; i++) {
                            tmpres[i][state[i]] = 'Q';
                        }
                        res.push_back(tmpres);
                    } else {
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
        for (int i=0; i<row; i++)
            if (state[i]==col || abs(row-i)==abs(col-state[i]))
                return false;
        return true;
    }
};

class Solution {
private:
    vector<vector<string> > res;
    int upperlim;
public:
    vector<vector<string> > solveNQueens(int n) {
        upperlim = (1 << n) - 1;//低n位全部置1
        vector<string> cur(n, string(n, '.'));
        helper(0,0,0,cur,0);
        return res;
    }

    void helper(const int row, const int ld, const int rd, vector<string>&cur, const int index)
    {
        int pos, p;
        if ( row != upperlim )
        {
            pos = upperlim & (~(row | ld | rd ));//pos中二进制为1的位，表示可以在当前行的对应列放皇后
            //和upperlim与运算，主要是ld在上一层是通过左移位得到的，它的高位可能有无效的1存在，这样会清除ld高位无效的1
            while ( pos )
            {
                p = pos & (~pos + 1);//获取pos最右边的1,例如pos = 010110，则p = 000010
                pos = pos - p;//pos最右边的1清0
                setQueen(cur, index, p, 'Q');//在当前行，p中1对应的列放置皇后
                helper(row | p, (ld | p) << 1, (rd | p) >> 1, cur, index+1);//设置下一行
                setQueen(cur, index, p, '.');
            }
        }
        else//找到一个解
            res.push_back(cur);
    }

    //第row行，第loc1(p)列的位置放置一个queen或者清空queen，loc1(p)表示p中二进制1的位置
    void setQueen(vector<string>&cur, const int row, int p, char val)
    {
        int col = 0;
        while(!(p & 1))
        {
            p >>= 1;
            col++;
        }
        cur[row][col] = val;
    }
};
