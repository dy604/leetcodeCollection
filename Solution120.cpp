
//题目120，Triangle 三角形

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int rowm = triangle.size();
        for (int i=1; i<rowm; i++) {
            int prem = triangle[i-1].size();
            int colm = triangle[i].size();

            triangle[i][0] += triangle[i-1][0];
            triangle[i][colm-1] += triangle[i-1][prem-1];

            for (int j=1; j<colm-1; j++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int size = triangle[rowm-1].size();
        int minTotal = triangle[rowm-1][0];

        for (int i=1; i<size; i++) {
            minTotal = min(minTotal, triangle[rowm-1][i]);
        }
        return minTotal;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int rowm = triangle.size();
        for (int i=rowm-2; i>=0; i--) {
            int colm = triangle[i].size();
            for (int j=0; j<colm; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
