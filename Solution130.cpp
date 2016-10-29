
//题目130，Surrounded Regions 包围区域

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if ((i==0 || i==board.size()-1 || j==0 || j==board[i].size()-1) && board[i][j]=='O')
                    solveDFS(board, i, j);
            }
        }
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (borad[i][j]=='O') board[i][j] = 'X';
                if (board[i][j]=='$') board[i][j] = 'O';
            }
        }
    }
    void solveDFS(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i>0 && board[i-1][j]=='O')
                solveDFS(board, i-1, j);
            if (j<board[i].size()-1 && board[i][j+1]=='O')
                solveDFS(board, i, j+1);
            if (i<board.size()-1 && board[i+1][j]=='O')
                solveDFS(board, i+1, j);
            if (j>1 && board[i][j-1]=='O')
                solveDFS(board, i, j-1);
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 || i==m-1 || j==0 || j==n-1) {
                    if (board[i][j] == 'O')
                        dfs(board, i, j);
                }

            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dir{{0, -1}, {-1,0}, {0,1}, {1,0}};
        board[x][y] = '$';
        for (int i=0; i<dir.size(); ++i) {
            int dx = x+dir[i][0], dy = y+dir[i][1];
            if (dx>=0 && dx<m && dy>0 && dy<n && board[dx][dy]=='O')
                dfs(board, dx, dy);
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        const int m = board.size();
        const int n = board[0].size();
        for (int i=0; i<n; i++) {
            bfs(board, 0, i);
            bfs(board, m-1, i);
        }
        for (int j=1; j<m-1; j++) {
            bfs(board, j, 0);
            bfs(board, j, n-1);
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '+')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j) {
        typedef pair<int, int> state_t;
        queue<state_t> q;
        const int m = board.size();
        const int n = board[0].size();

        auto is_valid = [&](const state_t &s) {
            const int x = s.first;
            const int y = s.second;
            if (x<0 || x>=m || y<0 || y>=n || board[x][y]!='O')
                return false;
            return true;
        };
        auto state_extend = [&](const state_t &s) {
            vector<state_t> res;
            const int x = s.first;
            const int y = s.second;
            //上下左右
            const state_t new_states[4] = {{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}};
            for (int k=0; k<4; ++k) {
                if (is_valid(new_states[k])) {
                    //既有标记功能又有去重功能
                    board[new_states[k].first][new_states[k].second] = '+';
                    res.push_back(new_states[k]);
                }
            }
            return res;
        };
        state_t start = {i,j};
        if (is_valid(start)) {
            board[i][j] = '+';
            q.push(start);
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto new_states = state_extend(cur);
            for (auto s : new_states)
                q.push(s);
        }
    }
};
