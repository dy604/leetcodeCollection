
//题目200，Number of Islands 岛屿的数量

public class Solution {
    static int[] dx = {-1, 0, 0, 1};
    static int[] dy = {0, 1, -1, 0};
    public static int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int islands = 0;
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    explore(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    public static void explore(char[][] grid, int i, int j) {
        grid[i][j] = 'X';
        for (int d=0; d<dx.length; d++) {
            if (i+dy[d]<grid.length && i+dy[d]>=0 && j+dx[d]<grid[0].length && j+dx[d]>=0
                && grid[i+dy[d]][j+dx[d]]=='1') {
                explore(grid, i+dy[d], j+dx[d]);
            }
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y) {
        if (x<0 || x>=grid.size()) return ;
        if (y<0 || y>=grid[0].size()) return;
        if (grid[x][y] != '1' || visited[x][y]) return ;
        visited[x][y] = true;
        dfs(grid, visited, x-1, y);
        dfs(grid, visited, x+1, y);
        dfs(grid, visited, x, y-1);
        dfs(grid, visited, x, y+1);
    }
};
