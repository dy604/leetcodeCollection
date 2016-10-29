
//题目218，The Skyline Problem 天际线问题

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buidings) {
        vector<pair<int, int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buidings) {
            //为了区分左右边界，将左边界的高度存为负数，这样遇到左边界就存入堆中，遇到右边界就删掉，然后看当前状态有无改变，改变了话就把左边界和当前的高度存入结果中.
            h.push_back({a[0], -a[2});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());//vector<pair<int, int>> h排序只根据key值排序
        m.insert(0);
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);//multiset会对插入的数进行排序
            else m.erase(m.find(a.second));
            cur = *m.rbegin();//取m的最后一个元素，即m中最大的一个元素
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
