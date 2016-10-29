
//题目48，Rotate Image 旋转图像

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        const int n = matrix.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n-i; ++j) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        for (int i=0; i<n/2; ++i) {
            for (int j=0; j<n; ++j) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        const int n = matrix.size();
        for (int i=0; i<n/2; ++i) {
            for (int j=0; j<n; ++j) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

//首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        const int n = matrix.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[j].end());
        }
    }
};
