
//题目36，Valid Sudoku 验证数独

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool used[9];
        for (int i=0; i<9; i++) {
            fill(used, used+9, false);
            for (int j=0; j<9; j++) {
                if (!check(board[i][j], used)) {
                    return false;
                }
            }
            fill(used, used+9, false);
            for (int j=0; j<9; j++) {
                if (!check(board[j][i], used)) {
                    return false;
                }
            }
        }
        for (int r=0; r<3; r++) {
            for (int c=0; c<3; c++) {
                fill(used, used+9, false);
                for (int i=r*3; i<r*3+3; i++) {
                    for (int j=c*3; j<c*3+3; j++) {
                        if (!check(board[i][j], used)) {
                            return false;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool check(char ch, used[9]) {
        if (ch == '.') {
            return true;
        }
        if (used[ch-'1']) {
            return false;
        }
        return used[ch-'1'] = true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int used1[9][9] = {0};
        int used2[9][9] = {0};
        int used3[9][9] = {0};
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = i/3*3 + j/3;
                    if (used1[i][num] || used2[j][num] || used3[k][num]) {
                        return false;
                    }
                    used1[i][num] = used2[j][num] = used[k][num] = 1;
                }
            }
        }
        return true;
    }
};
