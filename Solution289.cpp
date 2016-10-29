
//题目289，Game of Life 生命游戏

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        if (m==0 || n==0) {
            return;
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int count = 0;
                for (int k=max(i-1, 0); k<min(i+2, m); ++k) {
                    for (int g=max(i-1, 0); g<min(j+2, n); ++g) {
                        count += board[k][g] & 1;
                    }
                }
                if (count==3 || (count-board[i][j])==3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
