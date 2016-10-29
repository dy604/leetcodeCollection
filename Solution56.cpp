
//题目56，Merge Intervals 合并区间 题目57，Insert Interval

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool comp(const Interval &a, const Interval &b) {
        return (a.start < b.start);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        for (int i=0; i<intervals.size(); ++i)
            res = insert(res, intervals[i]);
        return res;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        vector<Interval>::iterator it = res.begin();
        int overlap = 0;
        while (it != res.end()) {
            if (newInterval.end > it->start) break;
            else if (newInterval.start > it->end) {}
            else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                ++overlap;
            }
            ++it;
        }
        if (overlap != 0) it = res.erase(it-overlap, it);
        res.insert(it, newInterval);
        return res;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        for (int i=0; i<intervals.size(); i++)
            insert(res, intervals[i]);
        return res;
    }
private:
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
