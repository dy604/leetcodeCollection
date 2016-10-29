
//题目268，Missing Number 丢失的数字

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            while (i<nums.size() && nums[i]==i) i++;
            while (i<nums.size() && nums[i] != i) {
                if (nums[i] >= nums.size() || nums[i] < 0) break;
                nums[i] = nums[i] ^ nums[nums[i]] ^ (nums[nums[i]] = nums[i]);
            }
        }
        for (int i=0; i<nums.size(); i++)
            if (nums[i] != i) return i;
        return nums.size();
    }
};

//易理解
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i=0; i<nums.size(); i++) {
            res ^= nums[i]^i;
        }
        return res;
    }
};

//易理解
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size()*(nums.size()+1)/2;
        for (int i=0; i<nums.size(); i++) {
            res -= nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int pre = -1;
        int cur = 0;
        int size = nums.size();
        while (cur < size) {
            if (nums[cur] != cur) {
                if (nums[cur] != size) {
                    swap(nums[cur], nums[nums[cur]]);
                } else {
                    pre = cur;
                    cur++;
                }
            } else {
                cur++;
            }
        }
        return pre == -1 ? size : pre;
    }
};
