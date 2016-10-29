
//题目18，4Sum，从给定数组中找到四个整数相加为target的数。要求a ≤ b ≤ c ≤ d

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        auto last = nums.end();
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (auto a=nums.begin(); a<prev(last,3); ++a) {
            for (auto b=next(a); b<prev(last,2); ++b) {
                auto c = next(b);
                auto d = prev(last);
                while (c < d) {
                    if (*a+*b+*c+*d<target) {
                        ++c;
                    } else if (*a+*b+*c+*d>target) {
                        --d;
                    } else {
                        res.push_back({*a, *b, *c, *d});
                        ++c;
                        --d;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<int(nums.size()-3); ++i) {
            for (int j=i+1; j<int(nums.size()-2); ++j) {
                int left = j+1, right = nums.size()-1;
                while (left < right) {
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
