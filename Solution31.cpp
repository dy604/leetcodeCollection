
//题目31，Next Permutation 下一个排列
//递减的序列没有下一个排列

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int k = -1;
        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = -1;
        for (int i=nums.size()-1; i>k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i, j, n = nums.size();
        for (i=n-2; i>=0; --i) {
            if (nums[i+1] > nums[i]) {
                for (j=n-1; j>=i; --j) {
                    if (nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
