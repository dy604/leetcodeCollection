
//题目85，Maximal Rectangle 最大矩形
//题目84，Largest Rectangle in Histogram

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int res = 0;
        vector<int> height;
        for (int i=0; i<matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j=0; j<matrix[i].size(); ++j) {
                height[j] = matrix[i][j]=='0' ? 0 : (1+height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        for (int i=0; i<height.size(); ++i) {
            if (s.empty() || height[s.top()]<=height[i]) s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp]*(s.empty() ? i : (i-s.top()-1)));
                --i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n+1, 0);
        for (int i=0; i<m; ++i) {
            stack<int> s;
            for (int j=0; j<n+1; ++j) {
                if (j<n) {
                    height[j] = matrix[i][j]=='1' ? height[j]+1 : 0;
                }
                while (!s.empty() && height[s.top()]>=height[j]) {
                    int cur = s.top(); s.pop();
                    res = max(res, height[cur]*(s.empty() ? j : (j-s.top()-1)));
                }
                s.push(i);
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left, n, 0);
        fill_n(right, n, n);
        fill_n(height, n, 0);
        int maxArea = 0;
        for (int i=0; i<m; i++) {
            int cur_left = 0;
            int cur_right = n;
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j+1;
                }
            }
            for (int j=n-1; j>=0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            for (int j=0; j<n; j++) {
                maxArea = max(maxArea, (right[j]-left[j])*height[j]);
            }
        }
        return maxArea;
    }
};
