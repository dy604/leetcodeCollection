
//题目252，Meeting Rooms 会议室
//题目253，Meeting Rooms II

class Solution {
public:
    bool canAttendMettings(vector<Interval>& Intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
                return a.start < b.start;
            });
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};
