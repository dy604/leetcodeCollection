
//题目229，Majority Element II 求众数之二
//题目169，Majority Element

//摩尔投票法
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int cnt1 = 0, cnt2 = 0, a = 0, b = 1;
        for (auto num : nums) {
            if (a == num) {
                cnt1++;
            } else if (b == num) {
                cnt2++;
            } else if (cnt1 == 0) {
                a = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                b = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (auto num : nums) {
            if (num == a) cnt1++;
            else if (num == b) cnt2++;
        }
        vector<int> res;
        if (cnt1 > nums.size()/3) res.push_back(a);
        if (cnt2 > nums.size()/3) res.push_back(b);
        return res;
    }
};
