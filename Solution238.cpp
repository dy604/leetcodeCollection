
//题目238，Product of Array Except Self 除本身之外的数组之积

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m = nums.size();
        vector<int> left(m);
        vector<int> right(m);
        left[0] = right[m-1] = 1;
        for (int i=1; i<m; i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        for (int i=m-2; i>=0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        for (int i=0; i<m; i++) {
            nums[i] = left[i] * right[i];
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m = nums.size();
        int left = 1;
        int right = 1;
        vector<int> res(m, 1);
        for (int i=0; i<m; i++) {
            res[i] *= left;
            left *= nums[i];
            res[m-1-i] *= right;
            right *= nums[m-1-i];
        }
        return res;
    }
};
