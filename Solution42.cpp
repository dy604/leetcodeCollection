
//题目42，Trapping Rain Water 收集雨水

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int *max_left = new int[n]();
        int *max_right = new int[n]();

        for (int i=1; i<n; i++) {
            max_left[i] = max(max_left[i-1], height[i-1]);
            max_right[n-1-i] = max(max_right[n-i], height[n-i]);
        }
        int sum = 0;
        for (int i=0; i<n; i++) {
            int heightEle = min(max_left[i], max_right[i]);
            if (heightEle > height[i]) {
                sum += heightEle - height[i];
            }
        }
        delete[] max_left;
        delete[] max_right;
        return sum;
    }
};

class Solution {
public:
    int trap(vector<int> &height) {
        int max = 0;
        for (int i=0; i<height.size(); i++)
            if (height[i] > height[max]) max = i;
        int water = 0;
        for (int i=0, peak=0; i<max; i++)
            if (height[i] > peak) peak = height[i];
            else water += peak-height[i];
        for (int i=height.size()-1, top=0; i>max; i--)
            if (height[i] > top) top = height[i];
            else water += top-height[i];
        return water;
    }
};

class Solution {
public: //借助辅助栈
    int trap(vector<int> &height) {
        stack<pair<int, int>> s;
        int water = 0;

        for (int i=0; i<height.size(); ++i) {
            int heightEle = 0;
            while (!s.empty()) {
                int bar = s.top().first;
                int pos = s.top().second;
                water += (min(bar, height[i]) - heightEle) * (i-pos-1);
                heightEle = bar;

                if (height[i] < bar)
                    break;
                else
                    s.pop();
            }
            s.push(make_pair(height[i], i));
        }
        return water;
    }
};

class Solution {
public: //动态规划
    int trap(vector<int> &height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i=0; i<n; i++) {
            di[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i=n-1; i>=0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] - height[i] > 0) res += (dp[i]-height[i]);
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0, left = 0, right = height.size()-1;
        while (left < right) {
            int mn = min(height[left], height[right]);
            if (height[left] == mn) {
                ++left;
                while (left<right && height[left]<mn) {
                    res += (mn - height[left]);
                    ++left;
                }
            } else {
                --right;
                while (left<right && height[right]<mn) {
                    res += (mn - height[right]);
                    --right;
                }
            }
        }
        return res;
    }
};
