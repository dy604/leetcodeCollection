
//��Ŀ51��N-Queens N�ʺ�����

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
        upperlim = (1 << n) - 1;//��nλȫ����1
        vector<string> cur(n, string(n, '.'));
        helper(0,0,0,cur,0);
        return res;
    }

    void helper(const int row, const int ld, const int rd, vector<string>&cur, const int index)
    {
        int pos, p;
        if ( row != upperlim )
        {
            pos = upperlim & (~(row | ld | rd ));//pos�ж�����Ϊ1��λ����ʾ�����ڵ�ǰ�еĶ�Ӧ�зŻʺ�
            //��upperlim�����㣬��Ҫ��ld����һ����ͨ������λ�õ��ģ����ĸ�λ��������Ч��1���ڣ����������ld��λ��Ч��1
            while ( pos )
            {
                p = pos & (~pos + 1);//��ȡpos���ұߵ�1,����pos = 010110����p = 000010
                pos = pos - p;//pos���ұߵ�1��0
                setQueen(cur, index, p, 'Q');//�ڵ�ǰ�У�p��1��Ӧ���з��ûʺ�
                helper(row | p, (ld | p) << 1, (rd | p) >> 1, cur, index+1);//������һ��
                setQueen(cur, index, p, '.');
            }
        }
        else//�ҵ�һ����
            res.push_back(cur);
    }

    //��row�У���loc1(p)�е�λ�÷���һ��queen�������queen��loc1(p)��ʾp�ж�����1��λ��
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
