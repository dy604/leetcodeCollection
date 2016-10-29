
//题目84，Largest Rectangle in Histogram 直方图中最大的矩形
//题目85，Maximal Rectangle

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res;
        for (int i=0; i<heights.size(); ++i) {
            if (i+1<heights.size() && heights[i]<=heights[i+1]) {
                continue;
            }
            int minH = heights[i];
            for (int j=i; j>=0; --j) {
                minH = min(minH, heights[j]);
                int area = minH*(i-j+1);
                res = max(res, area);
            }
        }
        return res;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i=0; i<heights.size(); ++i) {
            if (s.empty() || heights[s.top()]<heights[i]) s.push(i);
            else {
                int cur = s.top();
                s.pop();
                res = max(res, heights[cur]*(s.empty() ? i : (i-s.top()-1)));
                --i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i=0; i<heights.size(); ++i) {
            if (!s.empty() && heights[s.top()]>=heights[i]) {
                int cur = s.top(); s.pop();
                res = max(res, heights[cur]*(s.empty() ? i : (i-s.top()-1)));
            }
            s.push(i);
        }
        return res;
    }
};
