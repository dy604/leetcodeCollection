
//题目169，Majority Element 求众数
//题目229，Majority Element II

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int Idx = 0, count = 1;
        for (int i=1; i<nums.size(); ++i) {
            nums[Idx] == nums[i] ? ++count : --count;
            if (count == 0) {
                Idx = i;
                count = 1;
            }
        }
        return nums[Idx];
    }
};

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> mapping;
        for (int i=0; i<nums.size(); i++) {
            if (++mapping[nums[i]] > (nums.size()/2))
                return nums[i];
        }
        return 0;
    }
};
