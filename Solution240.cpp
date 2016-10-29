
//题目240，Search a 2D Matrix II 搜索一个二维矩阵之二

public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix==null || matrix.length<1 || matrix[0].length<1) return false;

        int col = matrix[0].length-1;
        int row = 0;
        while (col>=0 && row<=matrix.length-1) {
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                col--;
            } else if (target > matrix[row][col]) {
                row++;
            }
        }
        return false;
    }
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int len = matrix[0].size()-1;
        for (int i=0; i<matrix.size(); i++) {
            int j = binSearch(matrix[i], 0, len, target);
            if (matrix[i][j] == target)
                return true;
        }
        return false;
    }
    int binSearch(vector<vector<int>> &nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high  = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }
};

//分治法
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        return helper(matrix, 0, n-1, 0, m-1, target);
    }
    boolean helper(int[][] matrix, int rowStart, int rowEnd, int colStart, int colEnd, int target) {
        if (rowStart>rowEnd || colStart>colEnd)
            return false;
        int rm = (rowStart+rowEnd)/2, cm = (colStart + colEnd)/2;
        if (matrix[rm][cm] == target) {
            return true;
        } else if (matrix[rm][cm] > target) {
            return helper(matrix, rowStart, rm-1, colStart, cm-1, target) ||
                helper(matrix, rm, rowEnd, colStart, cm-1, target) ||
                helper(matrix, rowStart, rm-1, cm, colEnd, target);
        } else {
            return helper(matrix, rm+1, rowEnd, cm+1, colEnd, target) ||
                helper(matrix, rm+1, rowEnd, colStart, cm, target) ||
                helper(matrix, rowStart, rm, cm+1, colEnd, target);
        }
    }
}
