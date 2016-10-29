
//题目54，Spiral Matrix 螺旋矩阵 题目59，Spiral Matrix II

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> res;
        int nr = matrix.size();
        if (nr == 0)
            return res;
        int nc = matrix[0].size();
        if (nc == 0)
            return res;
        vector<int> nSteps{nc, nr-1};
        int iDir = 0;
        int ir = 0, ic = -1;
        while (nSteps[iDir%2]) {
            for (int i=0; i<nSteps[iDir%2]; ++i) {
                ir += dirs[iDir][0];
                ic += dirs[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDir%2]--;
            iDir = (iDir+1)%4;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> spiralOder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int c = m>n ? (n+1)/2 : (m+1)/2;
        int p = m, q = n;
        for (int i=0; i<c; ++i, p-=2, q-=2) {
            for (int col=i; col<i+q; ++col) {
                res.push_back(matrix[i][col]);
            }
            for (int row=i+1; row<i+p; ++row) {
                res.push_back(matrix[row][i+q-1]);
            }
            if (p==1 || q==1) break;
            for (int col=i+q-2; col>=i; --col) {
                res.push_back(matrix[i+p-1][col]);
            }
            for (int row=i+p-2; row>i; --row) {
                res.push_back(matrix[row][i]);
            }
        }
        return res;
    }
};
