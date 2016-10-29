
//��Ŀ48��Rotate Image ��תͼ��

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

//���ȶ�ԭ����ȡ��ת�þ���Ȼ���ÿ�е����ַ�ת�ɵõ����
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
