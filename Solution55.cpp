
//��Ŀ55��Jump Game ��Ծ��Ϸ, 45�⣬Jump Game II

//��̬�滮
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int i = 0;
        for (int reach=0; i<n && i<=reach; ++i) {
            reach = max(reach, i+nums[i]);
        }
        return i==n;
    }
};

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return true;
        int maxreach = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (maxreach <= 0)
                return false;
            maxreach = max(maxreach-1, nums[i]);
        }
        return true;
    }
};
