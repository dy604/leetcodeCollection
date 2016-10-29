
//题目73，Set Matrix Zeroes 矩阵赋零

//O(m*n)空间复杂度解法。
//直接新建一个和matrix等大小的矩阵，然后一行一行的扫，只要有0，就将新建的矩阵的对应行全赋0，行扫完再扫列，然后把更新完的矩阵赋给matrix即可.
//代码略

//使用额外O(m + n)的空间，设置两个bool数组，记录每行和每列是否存在0；
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i=0; i<m; i++) {
            if (row[i]) {
                for (int j=0; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (col[i]) {
                for (int j=0; j<m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};

//使用常数空间，直接复用矩阵数组的第一行与第一列来记录每行每列是否存在0；
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row_has_zero = false;
        bool col_has_zero = false;
        for (int i=0; i<m; i++) {
            if (matrix[i][0] == 0) {
                col_has_zero = true;
                break;
            }
        }
        for (int i=0; i<n; i++) {
            if (matrix[0][i] == 0) {
                row_has_zero = true;
                break;
            }
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i=1; i<m; i++) {
            if (matrix[i][0] == 0) {
                for (int j=1; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i=1; i<n; i++) {
            if (matrix[0][i] == 0) {
                for (int j=1; j<m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (col_has_zero) {
            for (int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (row_has_zero) {
            for (int i=0; i<n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
