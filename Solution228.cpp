
//题目228，Summary Ranges 总结区间

class Solution {
public:
    vector<string> summaryRange(vector<int> &nums) {
        vector<string> res;
        if (nums.size() < 1)
            return res;
        int begin = nums[0];
        int end = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]==end || nums[i]==end+1) {
                end = nums[i];
            } else {
                if (begin == end) {
                    res.push_back(to_string(begin));
                } else {
                    string s = to_string(begin) + "->" + to_string(end);
                    res.push_back(s);
                }
                begin = end = nums[i];
            }
        }
        if (begin == end) {
            res.push_back(to_string(begin));
        } else {
            string s = to_string(begin) + "->" + to_string(end);
            res.push_back(s);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        for (int i=0; i<nums.size(); i++) {
            int a = nums[i];
            while (i+1<nums.size() && (nums[i+1]-nums[i]==1)) {
                i++;
            }
            if (a != nums[i]) {
                string s = to_string(a) + "->" + to_string(nums[i]);
                res.push_back(s);
            } else {
                res.push_back(to_string(a));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int begin = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i+1==nums.size() || nums[i]+1!=nums[i+1]) {
                string s = to_string(nums[begin]);
                if (i!=begin) s += "->" + to_string(nums[i]);
                res.push_back(s);
                begin = i+1;
            }
        }
        return res;
    }
};
