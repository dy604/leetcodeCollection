
//题目57，Insert Interval 插入区间 题目56，Merge Intervals

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        int i = 0, overlap = 0, n = intervals.size();
        while (i < n) {
            if (newInterval.end < res[i].start) break;
            else if (newInterval.start > res[i].end) {}
            else {
                newInterval.start = min(newInterval.start, res[i].start);
                newInterval.end = max(newInterval.end, res[i].end);
                overlap++;
            }
            ++i;
        }
        if (overlap > 0)
            res.erase(res.begin()+i-overlap, res.begin()+i);
        res.insert(res.begin()+i-overlap, newInterval);
        return res;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        vector<Interval>::iterator it = res.begin();
        int overlap = 0;
        while (it != res.end()) {
            if (newInterval.end < it->start) break;
            else if (newInterval.start > it->end) {}
            else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                ++overlap;
            }
            ++it;
        }
        if (overlap != 0)
            it = res.erase(it-overlap, it);
        res.insert(it, newInterval);
        return res;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if (newInterval.end < it->start) {
                intervals.insert(it, newInterval);
                return intervals;
            } else if (newInterval.start > it->end) {
                it++;
                continue;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
