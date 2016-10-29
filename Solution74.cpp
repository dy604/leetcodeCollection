
//题目74，Search a 2D Matrix 搜索一个二维矩阵

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m*n-1;
        while (start != end) {
            int mid = (start+end-1)/2;
            if (matrix[mid/n][mid%n] < target)
                start = mid + 1;
            else
                end = mid;
        }
        return matrix[end/n][end%n] == target;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while (i<m && j>=0) {
            if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
};
